
#include <iostream>
#include "CSommet.hpp"
#include "Cexception.hpp"
#define OUT_OF_MEMORY_DEL_INDEX 3
#define OUT_OF_MEMORY_ADD_INDEX 4
#define ERR_TAILLE_ARR 1
#define ERR_TAILLE_PAR 2
#define BAD_REALLOC 123



CSommet::CSommet()
{
	pSOMArrivant = nullptr;
	pSOMPartant = nullptr;
	uiSOMCmptArr = 0;
	uiSOMCmptPart = 0;
}



CSommet::CSommet(int iNumero)
{
	uiSOMNumero = iNumero;//uiSOMNumero prend la valeur placé en paramètre
	pSOMPartant = nullptr;
	pSOMArrivant = nullptr;
	uiSOMCmptArr = 0;
	uiSOMCmptPart = 0;
}



CSommet::CSommet(CSommet & SOMParam)
{
	unsigned int uiBoucle1;
	uiSOMCmptArr = SOMParam.uiSOMCmptArr;//recopie de l'attribut uiSOMCmptArr
	uiSOMCmptPart = SOMParam.uiSOMCmptPart;//recopie de l'attribut uiSOMCmptPart

	pSOMArrivant = (CArc**)malloc(SOMParam.uiSOMCmptArr * sizeof(CArc*)); //allocation de pSOMArrivant
	pSOMPartant = (CArc**)malloc(SOMParam.uiSOMCmptPart * sizeof(CArc*)); //allocation de pSOMPartant

	/*pour chaque CArc arrivant sur le sommet*/
	for (uiBoucle1 = 0; uiBoucle1 < uiSOMCmptArr; uiBoucle1++) {
		pSOMArrivant[uiBoucle1] = new CArc(SOMParam.SOMLireArcArrivant()[uiBoucle1]->ARCLireDestination());
	}
	/*pour chaque CArc partant du sommet*/
	for (uiBoucle1 = 0; uiBoucle1 < uiSOMCmptPart; uiBoucle1++) {
		pSOMPartant[uiBoucle1] = new CArc(SOMParam.SOMLireArcPartant()[uiBoucle1]->ARCLireDestination());
	}
}



CSommet::~CSommet()
{
	unsigned int uiBoucle;

	/*pour chaque CArc arrivant sur le sommet*/
	for (uiBoucle = 0; uiBoucle < uiSOMCmptArr; uiBoucle++) {
		delete pSOMArrivant[uiBoucle]; //on désalloue *pSOMArrivant
	}

	/*pour chaque CArc partant du sommet*/
	for (uiBoucle = 0; uiBoucle < uiSOMCmptPart; uiBoucle++) {
		delete pSOMPartant[uiBoucle];//on désalloue *pSOMPartant
	}

	free(pSOMArrivant); //on désalloue pSOMArrivant
	free(pSOMPartant); //on désalloue pSOMPartant

	pSOMArrivant = nullptr;
	pSOMPartant = nullptr;
}



unsigned int CSommet::SOMLireNumero()
{
	return uiSOMNumero;
}



CArc **CSommet::SOMLireArcArrivant()
{
	return pSOMArrivant;
}



CArc ** CSommet::SOMLireArcPartant()
{
	return pSOMPartant;
}



void CSommet::SOMEcrireNumero(unsigned int uiNumero) 
{
	uiSOMNumero = uiNumero;
}



void CSommet::operator=(CSommet & SOMParam) 
{
	unsigned int uiBoucle1;
	uiSOMNumero = SOMParam.SOMLireNumero(); //recopie de l'attribut uiSOMNumero
	uiSOMCmptArr = SOMParam.uiSOMCmptArr; //recopie de l'attribut uiSOMCmptArr
	uiSOMCmptPart = SOMParam.uiSOMCmptPart;//recopie de l'attribut uiSOMCmptPart

	pSOMArrivant = (CArc**)malloc(SOMParam.uiSOMCmptArr * sizeof(CArc*)); //allocation de pSOMArrivant
	pSOMPartant = (CArc**)malloc(SOMParam.uiSOMCmptPart * sizeof(CArc*)); //allocation de pSOMPartant

	/*pour chaque CArc arrivant*/
	for (uiBoucle1 = 0; uiBoucle1 < uiSOMCmptArr; uiBoucle1++) {
		/*on alloue un CArc venant de SOMParam*/
		pSOMArrivant[uiBoucle1] = new CArc(SOMParam.SOMLireArcArrivant()[uiBoucle1]->ARCLireDestination());
	}

	/*pour chaque CArc partant*/
	for (uiBoucle1 = 0; uiBoucle1 < uiSOMCmptPart; uiBoucle1++) {
		/*on alloue un CArc venant de SOMParam*/
		pSOMPartant[uiBoucle1] = new CArc(SOMParam.SOMLireArcPartant()[uiBoucle1]->ARCLireDestination());
	}

}



void CSommet::SOMSupprimerArcArrivant(unsigned int uiPosition)
{
	/*exception si uiPosition est plus grand que le nombre d'arc arrivant sur le sommet*/
	if (uiPosition > uiSOMCmptArr) {
		CExeption EXEObjet(OUT_OF_MEMORY_DEL_INDEX);
		throw EXEObjet;	
	}

	/*recopie des valeurs de pSOMArrivant sauf l'arc arrivant en uiPosition*/
	for (unsigned int uiBoucle = uiPosition; uiBoucle < uiSOMCmptArr-1; uiBoucle++) 
	{
		pSOMArrivant[uiBoucle] = pSOMArrivant[uiBoucle + 1];
	}

	uiSOMCmptArr--;//on décremente uiSOMCmptArr de 1.
	pSOMArrivant=(CArc**)realloc(pSOMArrivant, uiSOMCmptArr * sizeof(CArc*)); //reallocation de pSOMArrivant avec la nouvelle valeur de uiSOMCmptArr

	/*exception si la reallocation à échoué*/
	if (pSOMArrivant == nullptr && uiPosition) {
		CExeption EXObj(BAD_REALLOC);
		throw EXObj;
	}
}



void CSommet::SOMSupprimerArcPartant(unsigned int uiPosition)
{
	/*exception si uiPosition est plus grand que le nombre d'arc partant sur le sommet*/
	if (uiPosition > uiSOMCmptPart) {
		CExeption EXEObjet(OUT_OF_MEMORY_DEL_INDEX);
		throw EXEObjet;
	}

	/*recopie des valeurs de pSOMPartant sauf l'arc partant en uiPosition*/
	for (unsigned int uiBoucle = uiPosition; uiBoucle < uiSOMCmptPart - 1; uiBoucle++)
	{
		pSOMPartant[uiBoucle] = pSOMPartant[uiBoucle + 1];
	}

	uiSOMCmptPart--;//on decremente uiSOMCmptPart de 1. 
	pSOMPartant=(CArc**)realloc(pSOMPartant, uiSOMCmptPart * sizeof(CArc*));//reallocation de pSOMPartant avec la nouvelle valeur de uiSOMCmptPart.

	/*exception si la reallocation à échoué*/
	if (pSOMPartant == nullptr && uiPosition) {
		CExeption EXObj(BAD_REALLOC);
		throw EXObj;
	}
}

void CSommet::SOMSupprimerArcPartantDeNumero(unsigned int uiNum)
{
	unsigned int uiPosition = 99999999;
	for (unsigned int uiBoucle = 0; uiBoucle < this->uiSOMCmptPart; uiBoucle++) {
		if (uiNum == pSOMPartant[uiBoucle]->ARCLireDestination()) {
			uiPosition = uiBoucle;
		}
	}
	if (uiPosition != 99999999) {
		SOMSupprimerArcPartant(uiPosition);
	}
}

void CSommet::SOMSupprimerArcArrivantDeNumero(unsigned int uiNum)
{
	unsigned int uiPosition = 99999999;
	for (unsigned int uiBoucle = 0; uiBoucle < this->uiSOMCmptArr; uiBoucle++) {
		if (uiNum == pSOMArrivant[uiBoucle]->ARCLireDestination()) {
			uiPosition = uiBoucle;
		}
	}
	if (uiPosition != 99999999) {
		SOMSupprimerArcArrivant(uiPosition);
	}
}



void CSommet::SOMModifierArcArrivant(unsigned int uiNum, CArc *ARCNewValeur)
{
	/*exception si uiNum est plus grand que le nombre d'arc arrivant sur le sommet*/
	if (uiNum > uiSOMCmptArr) {
		CExeption EXCObjet(ERR_TAILLE_ARR);
		throw(EXCObjet);
	}

	pSOMArrivant[uiNum] =new CArc(* ARCNewValeur);//le uiNum CArc* pointé par pSOMArrivant devient ARCNewValeur.
}



void CSommet::SOMModifierArcPartant(unsigned int uiNum, CArc *ARCNewValeur)
{
	/*exception si uiNum est plus grand que le nombre d'arc partant sur le sommet*/
	if (uiNum > uiSOMCmptPart) {
		CExeption EXCObjet(ERR_TAILLE_PAR);
		throw(EXCObjet);
	}

	pSOMPartant[uiNum] = ARCNewValeur;//le uiNum CArc* pointé par pSOMPartant devient ARCNewValeur.
}



/**
 * @pre si vous aviez la possibilter de ne pas choisir de position d'insertion par default elle sera inserer à la fin du tableau
 */
void CSommet::SOMAjouterArcPartant(unsigned int uiNum, CArc *ARCTableauSource)
{
	/*exception si uiNum est plus grand que le nombre d'arc partant + 1 sur le sommet*/
	if (uiNum > uiSOMCmptPart + 1) {
		CExeption EXEObjet(OUT_OF_MEMORY_ADD_INDEX);
		throw EXEObjet;
	}

	pSOMPartant=(CArc**)realloc(pSOMPartant, (uiSOMCmptPart + 1) * sizeof(CArc*)); //reallocation de pSOMPartant avec uiSOMCmptPart + 1 CArc*

	/*on recopie les valeurs de pSOMPartant en laissant pSOMPartant[uiNum] en doublon*/
	for (unsigned int uiBoucle = uiSOMCmptPart; uiBoucle < uiNum; uiBoucle--)
	{
		pSOMPartant[uiBoucle] = pSOMPartant[uiBoucle - 1];
	}

	pSOMPartant[uiNum] = new CArc(*ARCTableauSource);//pSOMPartant[uiNum] pointe vers le CArc* placé en paramètre.
	uiSOMCmptPart++;//on incrémente uiSOMCmptPart de 1.

}



/**
 * @pre si vous aviez la possibilter de ne pas choisir de position d'insertion par default elle sera inserer à la fin du tableau
 */
void CSommet::SOMAjouterArcArrivant(unsigned int uiNum, CArc *ARCTableauSource)
{
	/*exception si uiNum est plus grand que le nombre d'arc arrivant + 1 sur le sommet*/
	if (uiNum > uiSOMCmptArr + 1) {
		CExeption EXEObjet(OUT_OF_MEMORY_ADD_INDEX);
		throw EXEObjet;
	}

	pSOMArrivant=(CArc**)realloc(pSOMArrivant , (uiSOMCmptArr + 1) * sizeof(CArc*));//reallocation de pSOMArrivant avec uiSOMCmptArr + 1 CArc*

	/*on recopie les valeurs de pSOMArrivant en laissant pSOMArrivant[uiNum] en doublon*/
	for (unsigned int uiBoucle = uiSOMCmptArr; uiBoucle < uiNum; uiBoucle--)
	{
		pSOMArrivant[uiBoucle] = pSOMArrivant[uiBoucle - 1];
	}

	pSOMArrivant[uiNum] = new CArc(*ARCTableauSource);//pSOMArrivant[uiNum] pointe vers le CArc* placé en paramètre.
	uiSOMCmptArr++; //on incrémente uiSOMCmptArr de 1.
}



void CSommet::SOMAfficher() 
{
	unsigned int uiBoucle1;
	std::cout << "Sommet n°" << SOMLireNumero() << std::endl<<"arc Arrivant"<<std::endl ;// affichage du numéro du sommet
	
	/*on affiche les propriétés de chaque arc arrivant par le sommet*/
	for (uiBoucle1 = 0; uiBoucle1 < uiSOMCmptArr; uiBoucle1++) {
		pSOMArrivant[uiBoucle1]->ARCAfficher();
	}
	std::cout  << "arc PARTANT" << std::endl;

	/*on affiche les propriétés de chaque arc partant du sommet*/
	for (uiBoucle1 = 0; uiBoucle1 < uiSOMCmptPart; uiBoucle1++) {
		pSOMPartant[uiBoucle1]->ARCAfficher();
	}
}



unsigned int CSommet::SOMlireNbArcArrivant()
{
	return uiSOMCmptArr;
}



unsigned int CSommet::SOMlireNbArcPartant()
{
	return uiSOMCmptPart;
}



CSommet & CSommet::SOMReverse()
{
	CSommet * SOMTemp = new CSommet(*this);
	unsigned int uiBoucle;
	for (uiBoucle = 0; uiBoucle < uiSOMCmptArr; uiBoucle++) {
		delete pSOMArrivant[uiBoucle];
	}
	for (uiBoucle = 0; uiBoucle < uiSOMCmptPart; uiBoucle++) {
		delete pSOMPartant[uiBoucle];
	}
	free(pSOMArrivant);
	free(pSOMPartant);
	uiSOMCmptArr = SOMTemp->uiSOMCmptPart;
	uiSOMCmptPart = SOMTemp->uiSOMCmptArr;
	pSOMArrivant = (CArc**)malloc(SOMTemp->uiSOMCmptPart * sizeof(CArc*));
	//pSOMArrivant = new CArc*[SOMParam.uiSOMCmptArr];
	//pSOMPartant = new CArc*[SOMParam.uiSOMCmptPart];
	pSOMPartant = (CArc**)malloc(SOMTemp->uiSOMCmptArr * sizeof(CArc*));
	for (uiBoucle = 0; uiBoucle < uiSOMCmptArr; uiBoucle++) {
		pSOMArrivant[uiBoucle] = new CArc(SOMTemp->SOMLireArcPartant()[uiBoucle]->ARCLireDestination());
	}
	for (uiBoucle = 0; uiBoucle < uiSOMCmptPart; uiBoucle++) {
		pSOMPartant[uiBoucle] = new CArc(SOMTemp->SOMLireArcArrivant()[uiBoucle]->ARCLireDestination());
	}
	delete SOMTemp;
	return *this;
}



void CSommet::SOMAjouterArcPartant( CArc *ARCTableauSource)
{
	pSOMPartant=(CArc**)realloc(pSOMPartant, (uiSOMCmptPart + 1) * sizeof(CArc*));//reallocation de pSOMPartant avec 1 CArc* en plus.

	/*exception si la reallocation a échoué*/
	if (pSOMPartant == NULL) {
		CExeption EXObj(BAD_REALLOC);
		throw EXObj;
	}

	pSOMPartant[uiSOMCmptPart] = new CArc(*ARCTableauSource);//le uiSOMCmptPart CArc* de pSOMPartant devient ARCTableauSource
	uiSOMCmptPart++;//on incrémente uiSOMCmptPart de 1.
}



void CSommet::SOMAjouterArcArrivant( CArc *ARCTableauSource)
{
	pSOMArrivant=(CArc**)realloc(pSOMArrivant, (uiSOMCmptArr + 1) * sizeof(CArc*));//reallocation de pSOMArrivant avec 1 CArc* en plus.

	/*exception si la reallocation a échoué*/
	if (pSOMArrivant == nullptr) {
		CExeption EXObj(BAD_REALLOC);
		throw EXObj;
	}

	pSOMArrivant[uiSOMCmptArr] = new CArc (*ARCTableauSource); //le uiSOMCmptArr CArc* de pSOMArrivant devient ARCTableauSource
	uiSOMCmptArr++;// on incrémente uiSOMCmptArr de 1.
}

