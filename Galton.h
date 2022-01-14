// Fichier			Galton.h
// Auteur			Emilie Bressoud et Loic Brasey
// Date				11.01.22
//
// But				Ce fichier contient les définitions de la classe Galton
//
// Remarque
//
// Compilateur 	Apple clang 13.0.0
#ifndef LABO_08_O_GALTON_H
#define LABO_08_O_GALTON_H
#include <vector>		// pour vector

class Galton {
public:
	/**
	 * @name 	Galton	: une planche de Galton
	 * @brief	creation d'une planche de Galton
	 *
	 * @param 	hauteur : nombre de rangees
	 * @param 	billes	: nombre de billes
	 */
	Galton(unsigned hauteur, unsigned billes);
	/**
	 * @name		affichageBilles
	 * @brief 	affiche dans la console la distribution des billes dans les cases.
	 */
	void affichageBilles() const;

private:
	const char 	BILLE;
	const char 	ESPACE;
	const int 	GAUCHE;
	const int 	DROITE;
	unsigned 	h;
	unsigned 	b;
	std::vector<unsigned> resultat;
};

#endif //LABO_08_O_GALTON_H
