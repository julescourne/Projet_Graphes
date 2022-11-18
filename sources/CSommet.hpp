#ifndef C_SOMMET_H
#define C_SOMMET_H

#include "CArc.hpp"

class CSommet
{
private:
	unsigned int uiSOMNumero;//entier non signé correspondant au numéro du sommet.

	CArc **pSOMArrivant;//pointeur de pointeurs sur des CArc qui arrivent sur le sommet.

	CArc **pSOMPartant;//pointeur de pointeurs sur des CArc qui partent sur le sommet.

	unsigned int uiSOMCmptArr;//entier non signé correspondant au nombre de CArcs arrivant sur le sommet.

	unsigned int uiSOMCmptPart;//entier non signé correspondant au nombre de CArcs partant du sommet.



public:

    /**
	 * @Brief Constructeur par défaut.
	 */
	CSommet();

    /**
	 * @Brief Constructeur prenant un int en paramètre.
	 */
	CSommet(int iNumero);

	/**
	 * @Brief Constructeur prenant en paramètre un int et deux CArc**.
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
	 * @return uiSOMNumero - entier non signé correspondant au numéro du sommet.
	 *
	 * @Brief Renvoit le numero du Sommet sur lequel on se trouve : Accesseur en Lecture.
	 */
	 unsigned int SOMLireNumero();

	/**
	 * @return uiSOMCmptArr - entier non signé correspondant au nombre de CArcs arrivant sur le sommet.
	 *
	 * @Brief Méthode qui renvoie le nombre de CArc qui arrivent sur le sommet.
	 */
	 unsigned int SOMlireNbArcArrivant();

	/**
	 * @return uiSOMCmptPart - entier non signé correspondant au nombre de CArcs partant du sommet.
	 *
	 * @Brief Méthode qui renvoie le nombre de CArc qui partant du sommet.
	 */
	 unsigned int SOMlireNbArcPartant();

	/**
	 * @param[in] uiNumero - entier non signé correspondant au numéro du sommet à modifier.
	 *
	 * @Brief Defini ou modifie le numero du sommet concerné:Accesseur En Ecriture.
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
	  * @param[in] uiPosition - entier non signé correspondant au numéro de l'arc arrivant à supprimer.
	  *
	  * @Brief Supprime l'arc arrivant en uiPosition.
	  * @note Il faut au préable connaitre la position de l'arc à supprimer
	  */
	  void SOMSupprimerArcArrivant(unsigned int uiPosition);

	 /**
	  * @param[in] uiPosition - entier non signé correspondant au numéro de l'arc partant à supprimer.
	  *
	  * @Brief Supprime l'arc partant en uiPosition.
	  * @note Il faut au préable connaitre la position de l'arc à supprimer
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
	  * @param[in] uiNum - entier non signé correspondant au numéro de l'arc arrivant à modifier.
	  * @param[in] *ARCNewValeur - pointeur sur un CArc.
	  *
	  * @Brief Modifie l'arc arrivant en position uiNum par la valeur placé en paramètre.
	  * @note Il faut au préable connaitre la position de l'arc à modifier
	  */
	  void SOMModifierArcArrivant(unsigned int uiNum, CArc *ARCNewValeur);
	  
	 /**
	  * @param[in] uiNum - entier non signé correspondant au numéro de l'arc partant à supprimer.
	  * @param[in] *ARCNewValeur - pointeur sur un CArc.
	  *
	  * @Brief Modifie l'arc partant en position uiNum par la valeur placé en paramètre.
	  * @note Il faut au préable connaitre la position de l'arc à modifier.
	  */
	  void SOMModifierArcPartant(unsigned int uiNum, CArc *ARCNewValeur);
	
	 /**
	  * @param[in] uiNum - entier non signé correspondant au numéro de l'arc partant à ajouter.
	  * @param[in] *ARCTableauSource - pointeur sur un CArc.
	  *
	  * @Brief Ajoute un Arc partant précis.
	  */
	  void SOMAjouterArcPartant(unsigned int uiNum, CArc *ARCTableauSource);
	  
	 /**
	  * @param[in] uiNum - entier non signé correspondant au numéro de l'arc arrivant à ajouter.
	  * @param[in] *ARCTableauSource - pointeur sur un CArc.
	  *
	  * @Brief Ajoute un Arc arrivant précis.
	  */
	  void SOMAjouterArcArrivant(unsigned int uiNum, CArc *ARCTableauSource);
	  
	 /**
	  * @param[in] *ARCTableauSource - pointeur sur un CArc.
      *
	  * @Brief Surcharge de la méthode SOMAjouterArcPartant prenant un CArc* en paramètre. Cette surcharge ajoute un Arc partant à la fin du tableau.
	  */
	  void SOMAjouterArcPartant( CArc *ARCTableauSource);

	 /**
	  * @param[in] *ARCTableauSource - pointeur sur un CArc.
	  *
	  * @Brief Surcharge de la méthode SOMAjouterArcArrivant prenant un CArc* en paramètre. Cette surcharge ajoute un Arc arrivant à la fin du tableau.
	  */
	  void SOMAjouterArcArrivant( CArc *ARCTableauSource);

	 /**
	  * @Brief Méthode qui affiche le sommet.
	  */
	  void SOMAfficher();

	 /**
	  * @param[in] SOMvaleur - objet de type CSommet.
	  *
	  * @Brief Surcharge de l'opérateur égale entre deux objets de type CSommet. Cette surcharge permet de recopier les valeurs des attributs du CSommet de droite dans le CSommet de gauche.
	  */
	  void operator=(CSommet & SOMvaleur);
	
	 /**
	  * @return *this - objet de type CSommet.
	  *
	  * @Brief Méthode qui permet d'inverser les Arcs partant et les Arcs arrivant sur un CSommet.
	  */
	  CSommet & SOMReverse();
};
#endif
