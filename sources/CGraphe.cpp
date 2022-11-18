#include "Cexception.hpp"
#include "CGraphe.hpp"

#define NUMERO_DEL_INEXISTANTE 9
#define INDICE_INEXISTANT 10
#define BAD_REALLOC 126
#define POSITION_DEL_INEXISTANTE 30


using namespace std;

CGraphe::CGraphe()
{
	pGRAListe = nullptr;
	uiGRACmptSommet = 0;
}



CGraphe::CGraphe(CGraphe & GRAParam)
{
	uiGRACmptSommet = GRAParam.uiGRACmptSommet;//recopie de l'attribut uiGRACmptSommet.

	pGRAListe = new CSommet[uiGRACmptSommet];//allocation de pGRAListe.

	/*recopie de chaque CSommet de GRAParam dans pGRAListe*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRACmptSommet; uiBoucle++)
	{
		pGRAListe[uiBoucle] = GRAParam.pGRAListe[uiBoucle];
	}
}



CGraphe::CGraphe(CSommet & SOMList, unsigned int uiNbSommet)
{
	uiGRACmptSommet = uiNbSommet; //uiGRACmptSommet prend la valeur placé en paramètre dans le constructeur.
	
	*pGRAListe = SOMList; //la première valeur de pGRAListe prend la valeur SOMList.
}



CGraphe::~CGraphe()
{
	delete[] pGRAListe; //désallocation de pGRAListe.
}



void CGraphe::GRAAjouterSommet(unsigned int uiNum, CSommet & SOMParam)
{
	/*exception si l'argument uiNum est plus grand que uiGRACmptSommet+1*/
	if (uiNum > uiGRACmptSommet+1) {
		CExeption EXEObject(POSITION_DEL_INEXISTANTE);
		throw EXEObject;
	}

	CGraphe *GRAtemp = new CGraphe(*this); //On initialise un graphe temporaire par appelle du constructeur de recopie
	
	delete this;//désalloue le graphe sur lequel on travaille.

	uiGRACmptSommet = GRAtemp->uiGRACmptSommet + 1; //le nouveaux graphe sur lequel on travaille prend 1 CSommet en plus.

	pGRAListe = new CSommet[uiGRACmptSommet]; //On alloue pGRAListe en fonction de la nouvelle valeur de uiGRACmptSommet.

	/*recopie des valeurs des CSommets se situant avant la position à ajouté*/
	for (unsigned int uiBoucle = 0; uiBoucle <uiGRACmptSommet-1 ; uiBoucle++)
	{
		pGRAListe[uiBoucle] = GRAtemp->pGRAListe[uiBoucle];
	}

	/*recopie des valeurs des CSommets se situant après la position à ajouté*/
	for (unsigned int uiBoucle = uiGRACmptSommet - 1; uiBoucle >uiNum; uiBoucle--)
	{
		pGRAListe[uiBoucle] = pGRAListe[uiBoucle-1];
	}

	pGRAListe[uiNum] = SOMParam; //recopie de la valeur du CSommet à ajouter à la position uiNum.
}



void CGraphe::GRAAjouterSommet(CSommet & SOMParam)
{
	uiGRACmptSommet++; //on incrémente uiGRACmptSommet de 1.

	/*si uiGRACmptSommet = 1*/
	if (uiGRACmptSommet == 1)
		pGRAListe = new CSommet[uiGRACmptSommet]; //on alloue un sommet à pGRAListe.
	/*sinon*/
	else
	{
		CSommet* SOMtemp = new CSommet[uiGRACmptSommet]; // on alloue un pointeur temporaire avec uiGRACmptSommet sommets.

		/*on recopie les valeurs de pGRAListe dans SOMtemp*/
		for (unsigned int uiBoucle = 0; uiBoucle < uiGRACmptSommet - 1; uiBoucle++)
		{
			SOMtemp[uiBoucle] = pGRAListe[uiBoucle];
		}

		delete[] pGRAListe;// désallocation de pGRAListe.

		pGRAListe = new CSommet[uiGRACmptSommet];//allocation de pGRAListe avec la nouvelle valeur de uiGRACmptSommet.
		
		/*recopie des valeurs de SOMtemp dans pGRAListe*/
		for (unsigned int uiBoucle = 0; uiBoucle < uiGRACmptSommet - 1; uiBoucle++)
		{
			pGRAListe[uiBoucle] = SOMtemp[uiBoucle];
		}
		delete[] SOMtemp; ////désallocation de SOMtemp
	}

	pGRAListe[uiGRACmptSommet - 1] = SOMParam; //la derniere valeur de pGRAListe prend la valeur placé en paramètre.
}



void CGraphe::GRAAjouterArcEntreSommets(unsigned int uiNumDest, unsigned int uiNumPart)
{
	unsigned int uiPosition = 999999, uiPosition2 = 999999;
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRACmptSommet; uiBoucle++) {
		if (uiNumDest == pGRAListe[uiBoucle].SOMLireNumero()) {
			uiPosition = uiBoucle;
		}
		if (uiNumPart == pGRAListe[uiBoucle].SOMLireNumero()) {
			uiPosition2 = uiBoucle;
		}
	}
	if (uiPosition != 999999 && uiPosition2 != 999999) {
		CArc* arc1 = new CArc(uiNumDest);
		CArc* arc2 = new CArc(uiNumPart);

		pGRAListe[uiPosition].SOMAjouterArcArrivant(arc2);
		pGRAListe[uiPosition2].SOMAjouterArcPartant(arc1);
	}
}

void CGraphe::GRASupprimerSommet(unsigned int uiNum)
{
	unsigned int uiPosition=uiGRACmptSommet;

	/*Si le numéro du CSommet correspond à la valeur placé en argument*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRACmptSommet - 1; uiBoucle++) {
		if (pGRAListe[uiBoucle].SOMLireNumero() == uiNum) {
			uiPosition = uiBoucle;
		}
	}

	/*exception si uiNum est plus grand que le nombre de sommets*/
	if (uiNum == uiGRACmptSommet) {
		CExeption EXEObject(NUMERO_DEL_INEXISTANTE);
		throw EXEObject;
	}
	
	/*recopie des valeurs de pGRAListe sauf celle en uiNum position*/
	for (unsigned int uiBoucle = uiPosition ; uiBoucle < uiGRACmptSommet-1; uiBoucle++)
	{
		pGRAListe[uiBoucle] = pGRAListe[uiBoucle+1];
	}

	for (unsigned int uiBoucle = 0; uiBoucle < uiGRACmptSommet - 1; uiBoucle++) {
		pGRAListe[uiBoucle].SOMSupprimerArcArrivantDeNumero(uiNum);
		pGRAListe[uiBoucle].SOMSupprimerArcPartantDeNumero(uiNum);
	}

	uiGRACmptSommet--;// on décremente uiGRACmptSommet de 1.
}



void CGraphe::GRASupprimerSommet()
{
	uiGRACmptSommet--;//On décremente uiGRACmptSommet de 1.
}



void CGraphe::GRAModifierSommet(unsigned int uiNum, CSommet & SOMParam)
{
	/*exception si uiNum est plus grand que le nombre de sommets*/
	if (uiNum> uiGRACmptSommet)
	{
		CExeption EXObjet(INDICE_INEXISTANT);
		throw EXObjet;
	}

   pGRAListe[uiNum] = SOMParam;  //le uiNum CSommet pointé par pGRAListe devient SOMParam.
}



void CGraphe::GRAAfficher() 
{
	/*On affiche chaque CSommet pointé par pGRAListe*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRACmptSommet; uiBoucle++)
	{
		pGRAListe[uiBoucle].SOMAfficher();
	}
}



void CGraphe::GRAAfficherOrienter()
{
	/*pour chaque sommets*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRACmptSommet; uiBoucle++)
	{
		/*pour chaque arc partant de ce sommet*/
		for (unsigned int uiBoucle1 = 0; uiBoucle1 < pGRAListe[uiBoucle].SOMlireNbArcPartant(); uiBoucle1++)
			/*on affiche le sommet de départ et le sommet d'arrivé avec une flèche orienté*/
			cout << pGRAListe[uiBoucle].SOMLireNumero() << "-->" << pGRAListe[uiBoucle].SOMLireArcPartant()[uiBoucle1]->ARCLireDestination() << endl;

		/*pour chaque arc arrivant de ce sommet*/
		for (unsigned int uiBoucle1 = 0; uiBoucle1 < pGRAListe[uiBoucle].SOMlireNbArcArrivant(); uiBoucle1++)
			/*on affiche le sommet de départ et le sommet d'arrivé avec une flèche orienté*/
			cout << pGRAListe[uiBoucle].SOMLireNumero() << "<--" << pGRAListe[uiBoucle].SOMLireArcArrivant()[uiBoucle1]->ARCLireDestination() << endl;
	}
}



void CGraphe::operator =(CGraphe & GRAVal) 
{
	/*si pGRAListe n'est pas null, on le désalloue*/
	if (pGRAListe !=nullptr) {
		delete[] pGRAListe;
	}

	uiGRACmptSommet = GRAVal.uiGRACmptSommet;//on recopie la nouvelle valeur de uiGRACmptSommet

	pGRAListe = new CSommet[uiGRACmptSommet]; //allocation de pGRAListe avec la nouvelle valeur de uiGRACmptSommet

	/*recopie des valeurs des CSommets dans pGRAListe*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRACmptSommet; uiBoucle++)
	{
		pGRAListe[uiBoucle] = GRAVal.pGRAListe[uiBoucle];
	}

}



CSommet & CGraphe::GRAlireSommetA(unsigned int uiPosition) 
{
	/*exception si uiPosition est plus grand que le nombre de sommets*/
	if (uiPosition > uiGRACmptSommet)
	{
		CExeption EXObjet(INDICE_INEXISTANT);
		throw EXObjet;
	}

	return pGRAListe[uiPosition];//on retourne le uiPosition CSommet pointé par pGRAListe.
}



void CGraphe::GRAReverse()
{
	/*Pour chaque sommet du graphe*/
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRACmptSommet; uiBoucle++)
		pGRAListe[uiBoucle].SOMReverse(); //On inverse les arcs arrivant et les arcs partants.
}



unsigned int CGraphe::GRAGetNbSommet()
{
	return uiGRACmptSommet;//on retourne le nombre de sommets.
}



void CGraphe::GRASetNbSommet(unsigned int uiNbSommet)
{
	uiGRACmptSommet = uiNbSommet;//uiGRACmptSommet prend la valeur placé en paramètre de la méthode.
}

