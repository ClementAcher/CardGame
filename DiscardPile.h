#pragma once

#include "gemstones.h"
#include "CardFactory.h"
#include <iostream>
#include <vector>

//DiscardPile tient les cartes dans std::vector et est similaire à Deck.
//DiscardPile& operator+=(Card*) jette la carte dans la pile.
//Card* pickUp()renvoie et supprime la carte supérieure de la pile au rebut.
//Card* top()renvoie mais ne supprime pas la carte supérieure de la pile au rebut.
//void print(std::ostream&)  pour insérer toutes les cartes de DiscardPile dans std::ostream.
//Ajouter également l'opérateur d'insertion pour insérer seulement la carte supérieure de la pile au rebut à un flux std::ostream.
//DiscardPile possède un constructeur qui accepte un flux istream et construit un objet de type DiscardPile à partir du fichier.
//DiscardPile(const istream&, CardFactory*)

using namespace std;

class DiscardPile : public vector<Card*> {
public:
	DiscardPile();
	DiscardPile(istream&, CardFactory*);
	DiscardPile& operator += (Card*);
	bool estVide();
	Card* pickUp();
	Card* top();
	void print(std::ostream&);
	//void print(ostream&);

	friend ostream & operator << (ostream & o, DiscardPile & dp) {
		dp.print(o);
		return o;
	}
};