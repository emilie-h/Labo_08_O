// Fichier			Galton.cpp
// Auteur			Emilie Bressoud et Loic Brasey
// Date				11.01.22
//
// But				Creation d'une classe Galton, qui va simuler le lancement de
// 					chaque bille selon le nombre de fois qu'elle va tomber sur un
// 					clou. Apres chaque lances, le programme determine l'emplacement
// 					de la bille. A la fin de la simulation, on affiche dans la
// 					console la distribution des billes dans les cases.
//
// Remarque			On suppose que les clous sont arranges symetriquements
// 					et que la planche de Galton n'est pas truquee.
// 					(la probabilite de tomber a gauche est de 0.5)
//
// Compilateur 	Apple clang 13.0.0 et Mingw-w64 g++ 11.2.0

#include "Galton.h"
#include <random>
#include <iostream>

using namespace std;

Galton::Galton(unsigned hauteur, unsigned billes) : BILLE('*'), ESPACE(' '),
																	GAUCHE(0), DROITE(1),
																	h(hauteur), b(billes){
	//on change la taille du vecteur pour qu'elle corresponde au nombre de cases
	resultat.resize(h + 1);

	//seed, utiliser pour le nombre aleatoire
	random_device rd;

	//distribution generee de maniere aleatoire. Elle vaut 0 si la bille tombe a
	// gauche et 1 si elle tombe a droite
	uniform_int_distribution<int> distribution(GAUCHE,DROITE);

	//repartition des billes dans les cases
	for(int i = 0; i < b; ++i ){
		int noCase = 0;
		//a chaque impact de la bille avec les clous, jusqu'au dernier, on
		// genere le chiffre aleatoire, ce qui determinera a la toute fin la
		// position de la bille
		for (int j = 0; j < h; ++j ) {
			noCase += distribution(rd);
		}
		//On ajoute le resultat dans le vecteur
		++resultat.at(noCase);
	}
}

void Galton::affichageBilles() const{

	//determine le nombre maximal de lignes à afficher
	unsigned maxLigne = *(max_element(resultat.begin(), resultat.end()));

	//affichage de chaque ligne en partant du haut
	for(; maxLigne > 0; --maxLigne){
			for(unsigned a : resultat){
				//n'affiche que si la bille apparait dans la ligne
				cout << (a >= maxLigne ? BILLE : ESPACE) << ESPACE;
			}
			cout << endl;
	}
}
