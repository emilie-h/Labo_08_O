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


/**
 * @class Galton
 *
 * @brief classe simulant une planche de Galton.
 *
 * Classe simple avec un constructeur et une methode d'affichage,
 * permettant à l'utilisateur de réaliser une simulation de la planche de Galton
 * en instanciant un objet.
 * Par la suite il sera possible de d'afficher les résultats de la simulation
 * grâce à la methode \b affichageBilles() .
 *
 */
class Galton {
public:
	
	/**
	 * @name 	Galton()
	 * @brief	Constructeur de Galton
	 *
	 * Initialise les attribut de la classe en fonction des paramètre et
	 * affecte le vecteur de résultat par un simulation du jeu.
	 *
	 * @param 	hauteur  : nombre de rangees
	 * @param 	billes	: nombre de billes
	 */
	Galton(unsigned hauteur, unsigned billes);
	
	/**
	 * @fn		affichageBilles()
	 *
	 * @brief 	affiche dans la console la distribution des billes dans les cases.
	 *
	 * La fonction permet d'afficher dans la console un représentation graphique des
	 * résultat de la planche de Galton généré par le constructeur.
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
