// Graphe.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
NBSommets=3
	NBArcs=3
	Sommets=[
	Numero=1
	Numero=2
Numero=3
]
Arcs=[
Debut=1, Fin=2
Debut=2, Fin=3
Debut=3, Fin=1
]
*/

using namespace std;

#include <iostream>
#include "CGraphe.hpp"
#include "CString.hpp"
#include "CFichier.hpp"
#include "Cexception.hpp"

#define FILENO_OPEN 20 

/* u que on travaille sur unt type de fichier particulier alors la strategie repose la forme du fichier cette code ne peut etre coherente que sur le bon format
du fichier */
/**
 * @Param[in] FICTemp - objet de la classe CFichier correspondant au fichier à récuperer.
 * @Param[in] cBalise - objet de type char correspondant à la balise.
 * @Param[in] iNumBalise - objet de type int correspondant à l'occurrence de la balise.
 * @return *result - CString contenant le mot entre les balise.
 *
 * @Brief Méthode permettant de récupérer le mot entre des balises.
 *
 */
CString& getWordAfterBalise(CFichier &FICTemp, char cBalise, int iNumBalise)
{
	int iBalise = 0;
	CString *result = new CString();
	FICTemp.FICOpen();
	if (FICTemp.FICIsOpen()) {
		char cChar;
		while (!FICTemp.FICisOver() && iBalise != iNumBalise)
		{
			cChar = FICTemp.FICGetChar();
			if (cChar == cBalise)iBalise++;
		}
		if (iBalise == iNumBalise) {
			*result = FICTemp.FICGetWord();
		}
		FICTemp.FICClose();

	}
	return *result;
}



CGraphe & GetAndSetGrapheInFile(CString & STRFileName)
{
	CFichier  *Fichier = new CFichier(STRFileName);
	Fichier->FICOpen();
	if (Fichier->FICIsOpen()) {
		CString *temp = new CString();
		int iNbSommet;
		int iNbArc;
		int iNumSommet;
		int iArcDebut, iArcFin;
		CArc **ARCArrivant;
		CArc **ARCPartatant;
		CSommet **SOMSommet;

		*temp = getWordAfterBalise(*Fichier, '=', 1);
		iNbSommet = atoi(*temp);
		*temp = getWordAfterBalise(*Fichier, '=', 2);
		iNbArc = atoi(*temp);
		ARCArrivant = new CArc*[iNbArc];
		ARCPartatant = new CArc*[iNbArc];
		SOMSommet = new CSommet*[iNbSommet];
		for (int iBoucle = 0; iBoucle < iNbSommet; iBoucle++) {
			//int iBoucle1 = 0;
			*temp = getWordAfterBalise(*Fichier, '=', iBoucle + 4);
			iNumSommet = atoi(*temp);
			SOMSommet[iBoucle] = new CSommet(iNumSommet);
			//iBoucle1++;
		}
		int iNumBalise = (5 + iNbSommet);
		for (int iBoucle = 0; iBoucle < iNbArc; iBoucle++) {
			*temp = getWordAfterBalise(*Fichier, '=', iNumBalise);
			iArcDebut = atoi(*temp);
			//cout << iArcDebut << endl;
			ARCArrivant[iBoucle] = new CArc(iArcDebut);
			*temp = getWordAfterBalise(*Fichier, '=', iNumBalise + 1);
			iArcFin = atoi(*temp);
			//cout << iArcFin << endl;
			ARCPartatant[iBoucle] = new CArc(iArcFin);
			iNumBalise += 2;
		}
		for (int iBoucle = 0; iBoucle < iNbSommet; iBoucle++) {
			for (int iBoucle2 = 0; iBoucle2 < iNbArc; iBoucle2++) {
				if (SOMSommet[iBoucle]->SOMLireNumero() == ARCArrivant[iBoucle2]->ARCLireDestination())
					SOMSommet[iBoucle]->SOMAjouterArcPartant(ARCPartatant[iBoucle2]);
				if (SOMSommet[iBoucle]->SOMLireNumero() == ARCPartatant[iBoucle2]->ARCLireDestination())
					SOMSommet[iBoucle]->SOMAjouterArcArrivant(ARCArrivant[iBoucle2]);
			}

		}
		CGraphe *GRAFinal = new CGraphe();
		for (int iBoucle = 0; iBoucle < iNbSommet; iBoucle++)
		{
			GRAFinal->GRAAjouterSommet(*SOMSommet[iBoucle]);
		}
		return *GRAFinal;
	}
	else
	{
		CExeption EXOBj(FILENO_OPEN);
		throw EXOBj;
	}
}


int main(int argc, char **argv)
{

	try {
		argc = 2;
		if (argc > 1) {
			CGraphe* GRAGraphe = new CGraphe();
			CString *STRFileName = new CString("test.txt");
			cout << "Graphe contenu dans le fichier données  1 " << endl;
			*GRAGraphe = GetAndSetGrapheInFile(*STRFileName);
			GRAGraphe->GRAAfficherOrienter();
			cout << "Graphe renverser  " << endl;
			GRAGraphe->GRAReverse();
			GRAGraphe->GRAAfficherOrienter();
			cout << "je supprime le 1 " << endl;
			GRAGraphe->GRASupprimerSommet(1);
			GRAGraphe->GRAAfficherOrienter();
			cout << "creation et ajout d'un sommet  " << endl;
			CSommet *som = new CSommet(5);
			GRAGraphe->GRAAjouterSommet(*som);
			GRAGraphe->GRAAjouterArcEntreSommets(5, 2);
			GRAGraphe->GRAAjouterArcEntreSommets(3, 5);
			GRAGraphe->GRAAfficherOrienter();
			delete STRFileName;
		}
	}
	catch (CExeption EXCObjet) {
		cout << "Exception retourné avec le code erreur : " << EXCObjet.EXCLirevaleur() << endl;
	}
	return 0;
}