#ifndef C_GRAPHE_H
#define C_GRAPHE_H


#include "CSommet.hpp"


class CGraphe
{
private:
	CSommet *pGRAListe; //pointeur de CSommet.

	unsigned int uiGRACmptSommet; //entier non signé correspondant aux nombres de sommets du graphe.

public:
	/**
	 * @Brief Constructeur par défaut.
	 */
	CGraphe();

	/**
	 * @param[in] GRAParam - objet de type CGraphe.
	 *
	 * @Brief Constructeur de recopie d'un objet de type CGraphe.
	 */
	CGraphe(CGraphe & GRAParam);

	/**
	 * @param[in] SOMList - objet de type CSommet représentant le premier sommet du graphe à construire.
	 * @param[in] uiNbSommet - entier non signé représentant le nombre de sommet du graphe à construire.
	 *
	 * @Brief Constructeur prenant en argument un CSommet et un unsigned int.
	 */
	CGraphe(CSommet & SOMList, unsigned int uiNbSommet);

	/**
	 * @Brief Destructeur.
	 */
	~CGraphe();

	/**
	 * @param[in] uiNum - entier non signé représentant le numéro du sommet à ajouter
	 * @param[in] SOMParam - objet de type CSommet à ajouter au graphe
	 *
	 * @Brief Méthode ajoutant le sommet SOMParam à la position uiNum dans le graphe.
	 */
	void GRAAjouterSommet(unsigned int uiNum, CSommet & SOMParam);

	/**
	 * @param[in] SOMParam - objet de type CSommet à ajouter dans le graphe.
	 *
	 * @Brief Surcharge de la méthode GRAAjouterSommet ne prenant qu'un paramètre de type CSommet. Cette méthode permet d'ajouter un sommet en dernière position de pGRAListe.
	 */
	void GRAAjouterSommet(CSommet & SOMParam);

	/**
	 * @param[in] uiNumPart - entier non signé représentant le numero du sommet de départ de l'arc
	 * @param[in] uiNumDest - entier non signé représentant le numéro du sommet de destination de l'arc.
	 *
	 * @Brief Méthode permettant de créer un arc entre deux sommets
	 */
	void GRAAjouterArcEntreSommets(unsigned int uiNumDest, unsigned int uiNumPart);

	/**
	 * @param[in] uiNum - entier non signé représentant la poisition du sommet à supprimer.
	 *
	 * @Brief Méthode permettant de supprimer le sommet numéro uiNum
	 */
	void GRASupprimerSommet(unsigned int uiNum);

	/**
	 * @Brief Surcharge de la méthode GRASupprimerSommet ne prenant aucun argument. Cette méthode décrémente uiGRACmptSommet de 1 et réalloue pGRAListe.
	 *
	 */
	void GRASupprimerSommet();

	/**
	 * @param[in] uiNum - entier non signé représentant le numéro du sommet à modifier.
	 * @param[in] SOMParam - objet de type CSommet à modifier dans le graphe.
	 *
	 * @Brief Méthode qui modifie le sommet en position uiNum dans le graphe en le remplacent par SOMParam.
	 */
	void GRAModifierSommet(unsigned int uiNum, CSommet & SOMParam);

	/**
	 * @return uiGRACmptSommet - entier non signé représentant le nombre de sommet du graphe.
	 *
	 * @Brief retourne le nombre de sommet du graphe.
	 */
	unsigned int GRAGetNbSommet();

	/**
	 * @param[in] uiNbSommet - entier non signé représentant le nouveaux nombre de sommets du graphe
	 *
	 * @Brief Méthode qui modifie le nombre de sommet du graphe.
	 */
	void GRASetNbSommet(unsigned int uiNbSommet);

	/**
	 * @param[in] uiPosition - entier non signé représentant la position du sommet à lire.
	 * @return pGRAListe[uiPosition] - CSommet en position uiPosition.
	 *
	 * @Brief Méthode qui retourne le sommet en position uiPosition dans le graphe.
	 */
	CSommet & GRAlireSommetA(unsigned int uiPosition);

	/**
	 * @param[in] GRAVal - objet de type CGraphe.
	 *
	 * @Brief Surcharge de l'opérateur = entre deux objets de type CGraphe. Cette surcharge permet de recopier les valeurs des attributs
	 *        de l'objet de type CGraphe à droite de l'opérateur = dans l'objet de type CGraphe à gauche de l'opérateur =.
	 */
	void operator=(CGraphe & GRAVal);

	/**
	 * @Brief Méthode qui affiche le graphe.
	 */
	void GRAAfficher();

	/**
	 * @Brief Méthode qui affiche le graphe de facon orienté. On utilise "-->" ou "<--" pour afficher l'orientation de l'arc entre deux sommets.
	 */
	void GRAAfficherOrienter();

	/**
	 * @Brief Méthode qui inverse les arc arrivant et les arcs partants.
	 */
	void GRAReverse();

};
#endif
