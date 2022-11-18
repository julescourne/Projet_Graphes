#ifndef CSTRING
#define CSTRING



#include <stdio.h>
#include <iostream>


class CString
{
private:
	/**
	 * @Brief Un tableau de char.
	 */
	char* pcString;

	/**
	 * @Brief Taille du tableau.
	 */
	unsigned int uiLength;

public:

	/**
	 * @Brief Constructeur par defaut.
	 */
	CString();

	/**
	 * @param[in] String - objet de la classe CString.
	 * @Brief Constructeur de recopie prenant un CString en argument.
	 */
	CString(CString &STRString);

	/**
	 * @Brief Constructeur de recopie.
	 */
	~CString();
	
	/**
	 * @param[in] pcString - pointeur sur une chaine de caract�re constante.
	 * @Brief Constructeur recopiant dans pcString l'argument pcString.
	 */
	CString(const char* pcNewString);

	/**
	 * @return pcString - la chaine de charact�re apr�s modification.
	 *
	 * @Brief surcharge de type pour permettre la convertion de CString vers char *
	 */
	operator char* () { return pcString; }

	/**
	 * @return uiLength - La taille du tableau.
	 * @Brief Fonction qui retourne la taille du tableau pcString.
	 */
	unsigned int STRLireTaille();

	/**
	 * @return pcString - Le tableau de char.
	 * @Brief Fonction qui retourne le tableau pcString.
	 */
	char* STRLireTableau();

	/**
	 * @Brief Fonction qui affiche la chaine de caract�re contenu dans pcString.
	 */
	void STRAfficherChaine();

	/**
	 * @Param[in] cChaine - pointeur constant sur des char.
	 *
	 * @Brief Fonction qui modifie la chaine pcString en la remplacant par cChaine.
	 */
	void STRModifierChaine(const char *cChaine);

	/**
	 * @Param[in] uiPosition - Position du charact�re.
	 * @return pcString[uiPosition] - l'�lement en uiPosition point� par pcString.
	 *
	 * @Brief Fonction qui renvoie le charact�re point� par pcString en position uiPosition.
	 */
	char STRLireChar(unsigned int uiPosition);

	/**
	 * @param[in] STRString - objet de la classe CString.
	 *
	 * @Brief Surcharge de l'op�rateur + entre deux objet de la classe CString. 
	 * @Brief L'op�rareur + aura pour effet de concat�ner deux chaines de caract�res et de mettre le r�sultat dans pcString de l'objet qui appel la fonction.
	 */
	void operator+(CString STRString);

	/**
	 * @param[in] cLettre - char repr�sentant le charact�re � ajouter.
	 * @return pcString - la chaine de charact�re apr�s modification.
	 *
	 * @Brief Fonction qui ajoute un charact�re en bout de chaine.
	 */
	void STRAjouterChar(char cLettre)
	{
		if (uiLength==0) {
			pcString = new char[uiLength + 2];
			pcString[uiLength] = cLettre;
			pcString[uiLength + 1] = '\0';
			uiLength++;
		}
		else {
			char * pcNewString = new char[uiLength + 2];//On d�clare un pointeur temporaire.
			/*On recopie les charact�res de la chaine dans pcNewString*/
			for (unsigned int uiBoucle = 0; uiBoucle <uiLength; uiBoucle++) {
				pcNewString[uiBoucle] = STRLireChar(uiBoucle);
			}
			/*on ajoute le charact�re � la fin de la chaine pcNewString*/
			pcNewString[uiLength] = cLettre;
			pcNewString[uiLength + 1] = '\0';
			delete[] pcString;
			pcString = new char[uiLength + 2]; //r�allocation de pcString

			/*On recopie les charact�res de pcNewString dans la chaine*/
			for (unsigned int uiBoucle = 0; uiBoucle < uiLength + 1; uiBoucle++) {
				pcString[uiBoucle] = pcNewString[uiBoucle];
			}
			pcString[uiLength + 1] = '\0';
			uiLength++; //on r�ajuste la taille de la chaine

			delete []pcNewString; //d�sallocation de pointeur temporaire
		}		
	}

	/**
	 * @param[in] STRString - CString constant.
	 *
	 * @Brief Surcharge de l'op�rateur = entre un CString et un const CString.
	 */
	void operator=(const CString & STRString) {
		unsigned int uiBoucle = 0;
		uiLength = STRString.uiLength;
		pcString = new char[STRString.uiLength + 2];
		while (uiBoucle <= STRString.uiLength) {
			pcString[uiBoucle] = STRString.pcString[uiBoucle];
			uiBoucle++;
		}
		pcString[uiBoucle] = '\0';
	}
     

};



CString::CString()
{
	uiLength = 0;
	pcString = NULL;
}



CString::CString(CString & STRString)
{
	unsigned int uiBoucle = 0;

	uiLength = STRString.uiLength;
	pcString = new char[STRString.uiLength+2];

	while (uiBoucle <= STRString.uiLength) {
		pcString[uiBoucle] = STRString.pcString[uiBoucle];
		uiBoucle++;
	}
	pcString[uiBoucle] = '\0';
}



 CString::~CString()
{
	delete[] pcString;
	uiLength = 0;
}



CString::CString(const char *pcNewString)
{
	unsigned int uiBoucle, uiBoucle2 = 0;

	/*uiBoucle2 contiendra le nombre de caract�re de la chaine constante pcNewString*/
	while (pcNewString[uiBoucle2] != '\0') {
		uiBoucle2++;
	}

	pcString = new char[uiBoucle2+1];//On alloue la m�moire de pcString en fonction de la taille de pcNewString.

	/*On recopie les charact�res contenues dans pcNewString dans pcString*/
	for (uiBoucle = 0; uiBoucle < uiBoucle2; uiBoucle++) {
		pcString[uiBoucle] = pcNewString[uiBoucle];
	}
	pcString[uiBoucle] = '\0';
	uiLength = uiBoucle-1; //On indique la nouvelle taille de chaine.
}



unsigned int CString::STRLireTaille() 
{
	return uiLength;
}



void CString::STRAfficherChaine()
{
	std::cout << pcString << std::endl;
}



char*  CString::STRLireTableau()
{
	return pcString;
}



void CString::STRModifierChaine(const char *cChaine)
{
	unsigned int uiBoucle, uiBoucle2 = 0;

	/*uiBoucle2 contiendra le nombre de caract�re de la chaine cChaine*/
	while (cChaine[uiBoucle2] != '\0') {
		uiBoucle2++;
	}

	pcString = new char[uiBoucle2+1];//On alloue la m�moire de pcString en fonction de la taille de cChaine.

	/*On recopie les charact�res contenues dans cChaine dans pcString*/
	for (uiBoucle = 0; uiBoucle < uiBoucle2; uiBoucle++) {
		pcString[uiBoucle] = cChaine[uiBoucle];
	}

	pcString[uiBoucle] = '\0';
	uiLength = uiBoucle-1;//On indique la nouvelle taille de chaine.
}


char CString::STRLireChar(unsigned int uiPosition)
{
	return pcString[uiPosition];
}



void CString::operator+(CString STRString)
{
	unsigned int uiBoucle1, uiBoucle3;
	char *pcNewString;
	pcNewString = new char[uiLength + STRString.uiLength+2];
	for (uiBoucle1 = 0; uiBoucle1 < uiLength; uiBoucle1++) {
		pcNewString[uiBoucle1] = pcString[uiBoucle1];
	}
	for ( uiBoucle1 = uiLength ; uiBoucle1 <uiLength + STRString.uiLength; uiBoucle1++) {
		pcNewString[uiBoucle1] = STRString.pcString[uiBoucle1-uiLength];
	}
	pcNewString[uiBoucle1] = '\0';
	delete[] pcString;
	pcString = new char[uiLength + STRString.uiLength +2];
	for (uiBoucle1 = 0; uiBoucle1 < uiLength + STRString.uiLength; uiBoucle1++) {
		pcString[uiBoucle1] = pcNewString[uiBoucle1];
	}

	pcString[uiLength + STRString.uiLength] = '\0';
	uiLength = uiLength + STRString.uiLength;
	delete[] pcNewString;
}

std::ostream & operator<<(std::ostream& OParam, CString & STRParam)
{
	OParam << STRParam.STRLireTableau();
	return OParam;
}





#endif // 