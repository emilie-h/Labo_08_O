// Fichier     	Galton.cpp
// Auteur			Emilie Bressoud et Loic Brasey
// Date        	11.01.22
//
// But				Creation d'une classe Galton, qui va simuler le lancement de
// 					chaque bille selon le nombre de rangee. Apres chaque
// 					lances, le programme determine l'emplacement de la bille. A
// 					la fin de la simulation, il affiche dans la console la
// 					distribution des billes dans les cases.
//
// Remarque			On suppose que les clous sont arranges de maniere symetrique
// 					et que la planche de Galton n'est pas truquee.
// 					(la probabilite de tomber a gauche est de 0.5)
//
// Compilateur 	Apple clang 13.0.0
#include "Galton.h"
#include <random>
#include <iostream>

using namespace std;

Galton::Galton(unsigned hauteur, unsigned billes) {
	h = hauteur;
	b = billes;
	resultat.resize(h + 1);

	random_device rd;//seed
	uniform_int_distribution<int> distribution(0,1);

	//repartition des billes dans les cases
	for (int i = 0; i < b; ++i ){
		int noCase = 0;
		for (int j = 0; j < h; ++j ) {
			noCase += distribution(rd);
		}
		++resultat.at(noCase);
	}

}

void Galton::affichageBilles() const{
	const char bille = '*';
	const char espace = ' ';

	for(unsigned a : resultat){
		cout << a << ' ';
	}
	cout << endl;
	//determine le nombre maximal de lignes à afficher
	unsigned maxLigne = *(max_element(resultat.begin(), resultat.end()));

	//affichage de chaque ligne
	for(; maxLigne > 0; --maxLigne){
			for(unsigned a : resultat){
				if(a >= maxLigne){
					cout << bille << espace;
				}else{
					cout << espace << espace;
				}
			}
			cout << endl;
	}
}
