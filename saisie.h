// Fichier			saisie.h
// Auteur			Emilie Bressoud et Loic Brasey
// Date				11.01.22
// But				Ce fichier contient les déclarations de plusieurs fonctions de
//						saisie.
//
// Remarque
//
// Compilateur 	Apple clang 13.0.0 et Mingw-w64 g++ 11.2.0

#ifndef SAISIE_H
#define SAISIE_H

#include <string>
#include <iostream>
#include <iomanip>

/**
 *
 * @fn cleanBuffer()
 *
 * @brief Fonction pour réparer et vider le buffer cin.
 *
 * La fonction verifier l'état du buffer cin et le répare si besoin.\n
 * La fonction va ensuite vider le buffer cin.
 */
void cleanBuffer();

/**
 * @fn saisie<>()
 *
 * @brief Fonction de saisie multi-type simple.
 *
 * La fonction affiche la partie gauche du \b msgGauche et droite du \b msgDroite
 * dans un espacement donné \b spacing. Ensuite, la fonction demande une saisie de
 * type \b T. Si la saisie est incorrecte, la fonction recommence depuis le début.
 *
 * @tparam T
 * @param msgGauche
 * @param espacement
 * @param msgDroite
 * @return - Une valeur du type \b T
 */
template <typename T>
T saisie(const std::string&  msgGauche,
         int                 espacement   = 0,
         const std::string&  msgDroite = ""){
	
	// variable pour la saisie
	T sortie;
	
	// tant que la saisie est incorrecte
	do {
		
		// affichage de la partie gauche du message
		std::cout << msgGauche;
		
		// si un espacement est précisé on l'applique
		if (espacement)
			std::cout << std::setw(espacement - (int) msgGauche.size());
		
		// affichage de la partie droite du message
		std::cout << std::right << msgDroite << " : ";
		
		// Saisie
		std::cin >> sortie;
		
		// tant que la saisie est incorrecte
		// (répare et vide le buffer dans le cas échéant)
	}while(std::cin.fail() && (cleanBuffer(),1));
	
	// vider le buffer
	cleanBuffer();
	
	// retourne le résultat
	return sortie;
}

#endif // SAISIE_H
