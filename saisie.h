/*
-----------------------------------------------------------------------------------
Nom du fichier : saisie.h
Auteur(s)      : Loïc Brasey
Date creation  : 11-01-2022
Description    : Ce fichier contient les déclarations de plusieurs fonctions de
                 saisie.
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

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
 * La fonction affiche la partie gauche \b left_msg du et droite \b right_msg dans
 * un espacement donné \b spacing. Ensuite la fonction demande une saisie de
 * type \b T. Si la saisie est incorrecte la fonction recommence de puis le début.
 *
 * @tparam T
 * @param left_msg
 * @param spacing
 * @param right_msg
 * @return
 */
template <typename T>
T saisie(const std::string&  left_msg,
         int                 spacing   = 0,
         const std::string&  right_msg = ""){
	
	// variable pour la saisie
	T sortie;
	
	// tant que la saisie est incorrecte
	do {
		
		// affichage de la partie droite du message
		std::cout << left_msg;
		
		// si un spacing est précisé on l'applique
		if (spacing) std::cout << std::setw(spacing - (int) left_msg.size());
		
		// affichage de la partie gauche du message
		std::cout << std::right << right_msg << " : ";
		
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
