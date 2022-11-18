#include "CArc.hpp"

CArc::CArc() 
{
}

CArc::CArc(CArc & ARCParam)
{
	uiARCDestination = ARCParam.uiARCDestination; //On recopie l'attribut de ARCParam.
}

CArc::CArc(unsigned int uiValue)
{
	ARCEcrireDestination(uiValue); //On initialise la valeur de uiARCDestination avec la valeur uiValue.
}

void CArc::ARCAfficher() 
{
	std::cout << uiARCDestination << std::endl; //Affichage de la destination de l'arc.
}

unsigned int CArc::ARCLireDestination()
{
	return uiARCDestination; //retourne l'entier non signé correspondant à la destination de l'arc.
}

void  CArc::ARCEcrireDestination(unsigned int uiValue) 
{
	uiARCDestination = uiValue; //On affecte la valeur uiValue à uiARCDestination.
}





