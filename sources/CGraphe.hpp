#ifndef C_GRAPHE_H
#define C_GRAPHE_H


#include "CSommet.hpp"


class CGraphe
{
private:
	CSommet *pGRAListe; //pointeur de CSommet.

	unsigned int uiGRACmptSommet; //entier non sign� correspondant aux nombres de sommets du graphe.

public:
	/**
	 * @Brief Constructeur par d�faut.
	 */
	CGraphe();

	/**
	 * @param[in] GRAParam - objet de type CGraphe.
	 *
	 * @Brief Constructeur de recopie d'un objet de type CGraphe.
	 */
	CGraphe(CGraphe & GRAParam);

	/**
	 * @param[in] SOMList - objet de type CSommet repr�sentant le premier sommet du graphe � construire.
	 * @param[in] uiNbSommet - entier non sign� repr�sentant le nombre de sommet du graphe � construire.
	 *
	 * @Brief Constructeur prenant en argument un CSommet et un unsigned int.
	 */
	CGraphe(CSommet & SOMList, unsigned int uiNbSommet);

	/**
	 * @Brief Destructeur.
	 */
	~CGraphe();

	/**
	 * @param[in] uiNum - entier non sign� repr�sentant le num�ro du sommet � ajouter
	 * @param[in] SOMParam - objet de type CSommet � ajouter au graphe
	 *
	 * @Brief M�thode ajoutant le sommet SOMParam � la position uiNum dans le graphe.
	 */
	void GRAAjouterSommet(unsigned int uiNum, CSommet & SOMParam);

	/**
	 * @param[in] SOMParam - objet de type CSommet � ajouter dans le graphe.
	 *
	 * @Brief Surcharge de la m�thode GRAAjouterSommet ne prenant qu'un param�tre de type CSommet. Cette m�thode permet d'ajouter un sommet en derni�re position de pGRAListe.
	 */
	void GRAAjouterSommet(CSommet & SOMParam);

	/**
	 * @param[in] uiNumPart - entier non sign� repr�sentant le numero du sommet de d�part de l'arc
	 * @param[in] uiNumDest - entier non sign� repr�sentant le num�ro du sommet de destination de l'arc.
	 *
	 * @Brief M�thode permettant de cr�er un arc entre deux sommets
	 */
	void GRAAjouterArcEntreSommets(unsigned int uiNumDest, unsigned int uiNumPart);

	/**
	 * @param[in] uiNum - entier non sign� repr�sentant la poisition du sommet � supprimer.
	 *
	 * @Brief M�thode permettant de supprimer le sommet num�ro uiNum
	 */
	void GRASupprimerSommet(unsigned int uiNum);

	/**
	 * @Brief Surcharge de la m�thode GRASupprimerSommet ne prenant aucun argument. Cette m�thode d�cr�mente uiGRACmptSommet de 1 et r�alloue pGRAListe.
	 *
	 */
	void GRASupprimerSommet();

	/**
	 * @param[in] uiNum - entier non sign� repr�sentant le num�ro du sommet � modifier.
	 * @param[in] SOMParam - objet de type CSommet � modifier dans le graphe.
	 *
	 * @Brief M�thode qui modifie le sommet en position uiNum dans le graphe en le remplacent par SOMParam.
	 */
	void GRAModifierSommet(unsigned int uiNum, CSommet & SOMParam);

	/**
	 * @return uiGRACmptSommet - entier non sign� repr�sentant le nombre de sommet du graphe.
	 *
	 * @Brief retourne le nombre de sommet du graphe.
	 */
	unsigned int GRAGetNbSommet();

	/**
	 * @param[in] uiNbSommet - entier non sign� repr�sentant le nouveaux nombre de sommets du graphe
	 *
	 * @Brief M�thode qui modifie le nombre de sommet du graphe.
	 */
	void GRASetNbSommet(unsigned int uiNbSommet);

	/**
	 * @param[in] uiPosition - entier non sign� repr�sentant la position du sommet � lire.
	 * @return pGRAListe[uiPosition] - CSommet en position uiPosition.
	 *
	 * @Brief M�thode qui retourne le sommet en position uiPosition dans le graphe.
	 */
	CSommet & GRAlireSommetA(unsigned int uiPosition);

	/**
	 * @param[in] GRAVal - objet de type CGraphe.
	 *
	 * @Brief Surcharge de l'op�rateur = entre deux objets de type CGraphe. Cette surcharge permet de recopier les valeurs des attributs
	 *        de l'objet de type CGraphe � droite de l'op�rateur = dans l'objet de type CGraphe � gauche de l'op�rateur =.
	 */
	void operator=(CGraphe & GRAVal);

	/**
	 * @Brief M�thode qui affiche le graphe.
	 */
	void GRAAfficher();

	/**
	 * @Brief M�thode qui affiche le graphe de facon orient�. On utilise "-->" ou "<--" pour afficher l'orientation de l'arc entre deux sommets.
	 */
	void GRAAfficherOrienter();

	/**
	 * @Brief M�thode qui inverse les arc arrivant et les arcs partants.
	 */
	void GRAReverse();

};
#endif
