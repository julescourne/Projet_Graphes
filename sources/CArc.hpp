#ifndef C_ARC_H
#define C_ARC_H

#include <iostream>

/**
 * @Brief classe repr�sentant des arcs.
 */
class CArc
{
private:
	unsigned int uiARCDestination; // entier non sign� repr�sentant le num�ro du sommet de destination de l'arc

public:

	/**
	 * @Brief Constructeur par d�faut.
	 */
	CArc();

	/**
	 * @param[in] ARCParam - objet de type CArc.
	 *
	 * @Brief constructeur de recopie permet d'intinatialiser une instance de Carc grace � une autre existante
	 */
	CArc(CArc &  ARCParam);

	/**
	 * @param[in] uiValue - entier non sign� repr�sentant la destination du CArc.
	 *
	 * @Brief constructeur de confort qui fait le racourcie de deux operation declarer une CArc tout en affectons la destination
	 */
	CArc(unsigned int uiValue);

	/**
	 * @Brief M�thode qui affiche les caract�ristique du CArc.
	 */
	void ARCAfficher();

	/**
	 * @return uiARCDestination -  entier non sign� repr�sentant le num�ro du sommet de destination de l'arc
	 *
	 * @Brief accesseur en lecture de la destination de l'arc
	 */
	unsigned int ARCLireDestination();

	/**
	 * @param[in] uiValeur -  entier non sign� repr�sentant le num�ro du sommet de destination de l'arc
	 *
	 * @Brief accesseur en Ecriture de la destination de l'arc
	 */
	void ARCEcrireDestination(unsigned int uiValeur);

};
#endif
