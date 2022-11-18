#ifndef C_SOMMET_H
#define C_SOMMET_H

#include "CArc.hpp"

class CSommet
{
private:
	unsigned int uiSOMNumero;//entier non sign� correspondant au num�ro du sommet.

	CArc **pSOMArrivant;//pointeur de pointeurs sur des CArc qui arrivent sur le sommet.

	CArc **pSOMPartant;//pointeur de pointeurs sur des CArc qui partent sur le sommet.

	unsigned int uiSOMCmptArr;//entier non sign� correspondant au nombre de CArcs arrivant sur le sommet.

	unsigned int uiSOMCmptPart;//entier non sign� correspondant au nombre de CArcs partant du sommet.



public:

    /**
	 * @Brief Constructeur par d�faut.
	 */
	CSommet();

    /**
	 * @Brief Constructeur prenant un int en param�tre.
	 */
	CSommet(int iNumero);

	/**
	 * @Brief Constructeur prenant en param�tre un int et deux CArc**.
	 */
	//CSommet(int iNumero , CArc **pARCArrivant,CArc **pARCPartant);

	/**
	 * @Brief Constructeur de recopie.
	 */
	CSommet(CSommet & SOMParam);

	/**
	 * @Brief Destructeur.
	 */
	~CSommet();

	/**
	 * @return uiSOMNumero - entier non sign� correspondant au num�ro du sommet.
	 *
	 * @Brief Renvoit le numero du Sommet sur lequel on se trouve : Accesseur en Lecture.
	 */
	 unsigned int SOMLireNumero();

	/**
	 * @return uiSOMCmptArr - entier non sign� correspondant au nombre de CArcs arrivant sur le sommet.
	 *
	 * @Brief M�thode qui renvoie le nombre de CArc qui arrivent sur le sommet.
	 */
	 unsigned int SOMlireNbArcArrivant();

	/**
	 * @return uiSOMCmptPart - entier non sign� correspondant au nombre de CArcs partant du sommet.
	 *
	 * @Brief M�thode qui renvoie le nombre de CArc qui partant du sommet.
	 */
	 unsigned int SOMlireNbArcPartant();

	/**
	 * @param[in] uiNumero - entier non sign� correspondant au num�ro du sommet � modifier.
	 *
	 * @Brief Defini ou modifie le numero du sommet concern�:Accesseur En Ecriture.
	 */
     void SOMEcrireNumero(unsigned int uiNumero);

	 /**
	  * @return pSOMArrivant - pointeur de pointeurs sur des CArc qui arrivent sur le sommet.
	  *
	  * @Brief renvoi la liste d'addresse  de tous les arcs arrivant au Sommet.
	  */
	  CArc **SOMLireArcArrivant();

	 /**
	  * @return pSOMPartant - pointeur de pointeurs sur des CArc qui arrivent sur le sommet.
	  *
	  * @Brief renvoi la liste d'addresse  de tous les arcs partant du Sommet.
	  */
	  CArc **SOMLireArcPartant();

	 /**
	  * @param[in] uiPosition - entier non sign� correspondant au num�ro de l'arc arrivant � supprimer.
	  *
	  * @Brief Supprime l'arc arrivant en uiPosition.
	  * @note Il faut au pr�able connaitre la position de l'arc � supprimer
	  */
	  void SOMSupprimerArcArrivant(unsigned int uiPosition);

	 /**
	  * @param[in] uiPosition - entier non sign� correspondant au num�ro de l'arc partant � supprimer.
	  *
	  * @Brief Supprime l'arc partant en uiPosition.
	  * @note Il faut au pr�able connaitre la position de l'arc � supprimer
	  */
	  void SOMSupprimerArcPartant(unsigned int uiPosition);

	  /**
	   * @Brief Supprime les Arcs Partant du CSommet qui a pour numero uiNum
	   */
	  void SOMSupprimerArcPartantDeNumero(unsigned int uiNum);

	  /**
	  * @Brief Supprime les Arcs arrivant sur le CSommet qui a pour numero uiNum
	  */
	  void SOMSupprimerArcArrivantDeNumero(unsigned int uiNum);

	 /**
	  * @param[in] uiNum - entier non sign� correspondant au num�ro de l'arc arrivant � modifier.
	  * @param[in] *ARCNewValeur - pointeur sur un CArc.
	  *
	  * @Brief Modifie l'arc arrivant en position uiNum par la valeur plac� en param�tre.
	  * @note Il faut au pr�able connaitre la position de l'arc � modifier
	  */
	  void SOMModifierArcArrivant(unsigned int uiNum, CArc *ARCNewValeur);
	  
	 /**
	  * @param[in] uiNum - entier non sign� correspondant au num�ro de l'arc partant � supprimer.
	  * @param[in] *ARCNewValeur - pointeur sur un CArc.
	  *
	  * @Brief Modifie l'arc partant en position uiNum par la valeur plac� en param�tre.
	  * @note Il faut au pr�able connaitre la position de l'arc � modifier.
	  */
	  void SOMModifierArcPartant(unsigned int uiNum, CArc *ARCNewValeur);
	
	 /**
	  * @param[in] uiNum - entier non sign� correspondant au num�ro de l'arc partant � ajouter.
	  * @param[in] *ARCTableauSource - pointeur sur un CArc.
	  *
	  * @Brief Ajoute un Arc partant pr�cis.
	  */
	  void SOMAjouterArcPartant(unsigned int uiNum, CArc *ARCTableauSource);
	  
	 /**
	  * @param[in] uiNum - entier non sign� correspondant au num�ro de l'arc arrivant � ajouter.
	  * @param[in] *ARCTableauSource - pointeur sur un CArc.
	  *
	  * @Brief Ajoute un Arc arrivant pr�cis.
	  */
	  void SOMAjouterArcArrivant(unsigned int uiNum, CArc *ARCTableauSource);
	  
	 /**
	  * @param[in] *ARCTableauSource - pointeur sur un CArc.
      *
	  * @Brief Surcharge de la m�thode SOMAjouterArcPartant prenant un CArc* en param�tre. Cette surcharge ajoute un Arc partant � la fin du tableau.
	  */
	  void SOMAjouterArcPartant( CArc *ARCTableauSource);

	 /**
	  * @param[in] *ARCTableauSource - pointeur sur un CArc.
	  *
	  * @Brief Surcharge de la m�thode SOMAjouterArcArrivant prenant un CArc* en param�tre. Cette surcharge ajoute un Arc arrivant � la fin du tableau.
	  */
	  void SOMAjouterArcArrivant( CArc *ARCTableauSource);

	 /**
	  * @Brief M�thode qui affiche le sommet.
	  */
	  void SOMAfficher();

	 /**
	  * @param[in] SOMvaleur - objet de type CSommet.
	  *
	  * @Brief Surcharge de l'op�rateur �gale entre deux objets de type CSommet. Cette surcharge permet de recopier les valeurs des attributs du CSommet de droite dans le CSommet de gauche.
	  */
	  void operator=(CSommet & SOMvaleur);
	
	 /**
	  * @return *this - objet de type CSommet.
	  *
	  * @Brief M�thode qui permet d'inverser les Arcs partant et les Arcs arrivant sur un CSommet.
	  */
	  CSommet & SOMReverse();
};
#endif
