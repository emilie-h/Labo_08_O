// Fichier		main.cpp
// Auteur		Emilie Bressoud et Loic Brasey
// Date			11.01.22
//
// But			Simuler une expérience d'une planche de Galton. A la fin du
// 				programme, le nombre de billes dans chaque case est affiche
// 				dans la console.
//
// Remarque		Le programme ne prend pas en compte si l'utilisateur entre plus
// 				d'un seul caractère.
//
// Compilateur Apple clang 13.0.0 et Mingw-w64 g++ 11.2.0

#include <iostream> //pour cout
#include <cstdlib>  //pour EXIT_SUCCESS
#include <string>   //pour string
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
							MSG_HAUTEUR_LIM   = "[" + to_string(MIN_HAUTEUR) + "..."
															+ to_string(MAX_HAUTEUR) + "]",
			 		 		MSG_BILLES 			= "nbre billes",
							MSG_BILLES_LIM    = "[" + to_string(MIN_BILLES)+ "..."
		                                       + to_string(MAX_BILLES) + "]",
			 		 		MSG_RECOMMENCER 	= "Voulez-vous recommencer [O|N]",
			 		 		MSG_FIN 				= "Presser ENTER pour quitter";
							

	const char	 		SAISIE_OUI			= 'O',
							SAISIE_NON        = 'N';

	//autres variables
	unsigned hauteur, billes;
	char     reponse;
	
	//affichage du debut du programme
	cout << MSG_BIENVENUE << endl;
	
	// Boucle principale
	do {

		//entrées utilisateurs avec vérification des saisies
		do { hauteur = saisie<unsigned>(MSG_HAUTEUR, ESPACEMENT,MSG_HAUTEUR_LIM);
		}while(!((hauteur >= MIN_HAUTEUR) && (hauteur <= MAX_HAUTEUR)));

		do { billes = saisie<unsigned>(MSG_BILLES, ESPACEMENT, MSG_BILLES_LIM);
		}while(!((billes >= MIN_BILLES) && (billes <= MAX_BILLES)));

		//lancement du jeu et son affichage
		Galton jeu(hauteur, billes);
		jeu.affichageBilles();
		
		//saisie utilisateur pour redémarrer avec verification
		do { reponse = saisie<char>(MSG_RECOMMENCER);
		}while(!((reponse == SAISIE_NON) || (reponse == SAISIE_OUI)));
		
	//recommence que lorsque l'utilisateur accepte de recommencer
	}while(reponse == SAISIE_OUI);

	//fin de programme
	std::cout << MSG_FIN;
	cleanBuffer();
	return EXIT_SUCCESS;
}
