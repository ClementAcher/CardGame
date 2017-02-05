#pragma once

#include <list>
#include <string>
#include "Gemstones.h"
#include "CardFactory.h"

//	La classe TradeArea devra tenir ouvertement les cartes et supporte de l'acc�s al�atoire d'insertion et de suppression.
//	TradeArea tient les cartes dans std::list.
//	TradeArea& operator+=(Card*) ajoute une carte � l��change mais il ne v�rifie pas si c'est l�gal de placer la carte. 
//	bool legal(Card*)renvoie true si la carte peut �tre l�galement ajout� � l��change, i.e., une carte de m�me pierre est d�j� en �change.
//	Card* trade(string) supprime de l��change une carte du correspondant nom.
//	int numCards() renvoie le nombre courant de cartes en �change.
//	Ajouter �galement l'op�rateur d'insertion pour ins�rer toutes les cartes en �change dans std::ostream.
//	TradeArea poss�de un constructeur qui accepte un flux istream et construit un objet de type TradeArea � partir du fichier.
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