#include "annexe.h"
#include <iostream>

using namespace std;
void viderBuffer() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void affichageDebutJeu(unsigned& h, unsigned& b) {
	cout <<"ce programme ..." << endl;
	cout << "hauteur [1..100] : ";
	//verifier Saisie
	cin >> h;
	cout << "nbre billes [1..1000] : ";
	//verifier Saisie
	cin >> b;
}
void affichageRecommencer(char& saisie) {
	std::cout << "voulez-vous recommencer [O|N] : ";
	std::cin >> saisie;
}