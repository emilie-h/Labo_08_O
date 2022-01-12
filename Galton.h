#ifndef LABO_08_O_GALTON_H
#define LABO_08_O_GALTON_H
#include <vector>

class Galton {
public:
	Galton(unsigned hauteur, unsigned billes);
	void affichageBilles() const;

private:
	unsigned h;
	unsigned b;
	std::vector<unsigned> resultat;
};


#endif //LABO_08_O_GALTON_H
