/*
-----------------------------------------------------------------------------------
Nom du fichier : saisie.cpp
Auteur(s)      : Loïc Brasey
Date creation  : 11-01-2022
Description    : Ce fichier contient les définitions de plusieurs fonctions de
                 saisie.
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

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
