#pragma once

#include <list>
#include <string>
#include "Gemstones.h"
#include "CardFactory.h"

//	La classe TradeArea devra tenir ouvertement les cartes et supporte de l'accès aléatoire d'insertion et de suppression.
//	TradeArea tient les cartes dans std::list.
//	TradeArea& operator+=(Card*) ajoute une carte à l’échange mais il ne vérifie pas si c'est légal de placer la carte. 
//	bool legal(Card*)renvoie true si la carte peut être légalement ajouté à l’échange, i.e., une carte de même pierre est déjà en échange.
//	Card* trade(string) supprime de l’échange une carte du correspondant nom.
//	int numCards() renvoie le nombre courant de cartes en échange.
//	Ajouter également l'opérateur d'insertion pour insérer toutes les cartes en échange dans std::ostream.
//	TradeArea possède un constructeur qui accepte un flux istream et construit un objet de type TradeArea à partir du fichier.
//	TradeArea(const istream&, CardFactory*)

using namespace std;

class TradeArea {
	list<Card *> listeCartes;
public:
	TradeArea& operator += (Card*);
	bool legal(Card*);
	Card* trade(std::string);
	int numCards();
	bool estVide();
	void afficherDerniere();
	TradeArea(istream&, CardFactory*);
	list<Card *> & getListeCartes();
	TradeArea();

	friend ostream& operator<<(ostream& out, const TradeArea& t) {
		if (t.listeCartes.size() == 0) {
			out << "Zone d'echange vide" << endl;
		}
		else {
			for (auto& c : t.listeCartes) {
				out << c->getName() << " ";
			}
		}
		cout << endl;
		return out;
	};
};