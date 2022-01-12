// Fichier     main.cpp
// Auteur		Emilie Bressoud et Loic Brasey
// Date        11.01.22
//
// But			Simuler une experience d'une planche de Galton. A la fin du
// programme, le nombre de billes dans chaque case est afficher dans la console.
//
// Remarque
//
// Compilateur Apple clang 13.0.0
#include <iostream>
#include <cstdlib>
#include <climits>
#include "Galton.h"
#include "annexe.h"
#include "saisie.h"


int main() {
	//variable constante
const std::string MSG_FIN = "Presser ENTER pour quitter";


	//variables de test
	unsigned hauteur, billes;

	char saisieUtilisateur = 'O';
	bool recommencerJeu = true;
	while(recommencerJeu) {
		affichageDebutJeu(hauteur, billes);
		Galton game(hauteur, billes);
		game.affichageBilles();
		affichageRecommencer(saisieUtilisateur);
		if(saisieUtilisateur != 'O'){
			recommencerJeu = false;
		}
	}

	//fin de programme
	viderBuffer();
	std::cout << MSG_FIN;
	viderBuffer();
	return EXIT_SUCCESS;
}
