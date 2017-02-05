#pragma once

#include <vector>
#include <iostream>
#include "Gemstones.h"


//	Deck est simplement une classe d�riv�e de std::vector.
//	Card* draw()retourne et supprime la carte sup�rieure du Deck.
//	Ajouter �galement l'op�rateur d'insertion pour ins�rer toutes les cartes du jeu dans un fichier std::ostream.
//	Deck poss�de un constructeur qui accepte un istream et construit un objet de type Deck � partir du fichier.
//	Deck(const istream&, CardFactory*)

// EXCEPTION

class EmptyDeck : public exception{
public:
	virtual const char* what() const throw() {
		return "Impossible de tirer une carte -- deck vide";
	}
};

class Deck: public vector<Card*> {
public:
	Deck();
	Card* draw(); 
	Deck( istream&, CardFactory*);
	friend std::ostream& operator<<(std::ostream& os, const Deck& d)
	{
		for (int i = 0; i < d.size(); i++)
		{
			os << (*((Card*) d.at(i))).getName()<<" ";
		}
		return os;
	}
};


