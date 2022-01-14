// Fichier		main.cpp
// Auteur		Emilie Bressoud et Loic Brasey
// Date			11.01.22
//
// But			Simuler une experience d'une planche de Galton. A la fin du
// 				programme, le nombre de billes dans chaque case est affiche
// 				dans la console.
//
// Remarque
//
// Compilateur Apple clang 13.0.0 et Mingw-w64 g++ 11.2.0

#include <iostream>
#include <cstdlib> //pour EXIT_SUCCESS
#include <string> //pour string
#include "Galton.h"
#include "saisie.h"
using namespace std;

int main() {
	//variables constantes
	const unsigned 	MIN_HAUTEUR 		= 1,
						 	MAX_HAUTEUR 		= 100,
						 	MIN_BILLES 			= 1,
						 	MAX_BILLES			= 1000,
						 	ESPACEMENT 			= 23;

	const string 		MSG_BIENVENUE 		= "ce programme ...",
			 		 		MSG_HAUTEUR 		= "hauteur",
			 		 		MSG_BILLES 			= "nbre billes",
			 		 		MSG_RECOMMENCER 	= "Voulez-vous recommencer [O|N]",
			 		 		MSG_FIN 				= "Presser ENTER pour quitter";

	const char	 		SAISIE_OUI			= 'O';

	//autres variables
	unsigned hauteur, billes;

	do {
		//affichage du debut du programme
		cout << MSG_BIENVENUE << endl;

		//entrees utilisateurs avec verification des saisies
		hauteur = saisie<unsigned>(MSG_HAUTEUR, ESPACEMENT, "[" + to_string(MIN_HAUTEUR)
											+ "..." + to_string(MAX_HAUTEUR) + "]");

		billes = saisie<unsigned>(MSG_BILLES, ESPACEMENT, "[" + to_string(MIN_BILLES)
											+ "..." + to_string(MAX_BILLES) + "]");

		//lancement du jeu et son affichage
		Galton jeu(hauteur, billes);
		jeu.affichageBilles();

		//recommence que lorsque l'utilisateur accepte de recommencer
	}while(saisie<char>(MSG_RECOMMENCER) == SAISIE_OUI);

	//fin de programme
	std::cout << MSG_FIN;
	cleanBuffer();
	return EXIT_SUCCESS;
}
