// Fichier			saisie.cpp
// Auteur			Emilie Bressoud et Loic Brasey
// Date				11.01.22
//
// But				Ce fichier contient les définitions de plusieurs fonctions de saisie.
//
// Remarque
//
// Compilateur		Apple clang 13.0.0 et Mingw-w64 g++ 11.2.0

#include "saisie.h"
#include <iostream> // pour cin
#include <limits>   // pour numeric_limits

using namespace std;

void cleanBuffer(){
	
	// répare le buffer si besoin
	if(cin.fail()) cin.clear();
	
	// vider le buffer
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
}
