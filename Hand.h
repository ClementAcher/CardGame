#pragma once

#include "Card.h"
#include "Gemstones.h"
#include "CardFactory.h"
#include <iostream>

//Hand& operator+=(Card*) adds the card to the rear of the hand
//Card* play() returns and removes the top card from the player's hand.  
//Card* top() returns but does not remove the top card from the player's hand. 
//Card* operator[](int) returns and removes the Card at a given index.
//Also add the insertion operator to print Hand on an std::ostream.The hand should print all the cards in order.
//Hand needs a constructor which accepts an istream and reconstruct the Hand from file.
//Hand(const istream&, CardFactory*

// TODO : Outofindex pour []?

using namespace std;

// Exception

class EmptyHand : public exception {
public:
	virtual const char* what() const throw() {
		return "Pas de carte dans la main";
	}
};

// Classe

class Hand {
	vector<Card*> vec_carte;
public:
	Hand();
	Hand(istream&, CardFactory*);

	Card* play(); // renvoie et supprime
	Card* top(); // renvoie sans supprimer
	Card* operator[](int); // renvoie et supprime
	Card* show(int); // renvoie sans supprimer
	int getSize();
	Hand& operator+=(Card*);
	Card* derniereCarteAjoutee();
	bool estVide();

	friend ostream& operator<<(ostream& o, Hand& h) {
		for (auto carte : h.vec_carte) {
			if(carte != nullptr)
				o << *carte << " ";
		}
		cout << endl;
		return o;
	};
};
