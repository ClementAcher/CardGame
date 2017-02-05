#pragma once

#include <string>
#include <iostream>
#include "Player.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "CardFactory.h"

//  Table permettra de g�rer tous les composants du jeu.Elle tiendra deux objets de type Player, Deck et DiscardPile, ainsi que TradeArea.
//  bool win(std::string& renvoie true si le joueur a gagn�.Le nom du joueur est transmis par r�f�rence(en argument).
//  La condition de gagner est que toutes les cartes de Deck doivent avoir �t� reprises et alors le joueur avec le plus de pi�ces gagne.
//	void printHand(bool) affiche la premi�re carte de la main du joueur(avec l�argument false) ou l'ensemble de la main du joueur  (avec argument true). 
//	Ajouter �galement l'op�rateur d'insertion pour afficher Table dans std::ostream. Les deux joueurs, la pile au rebut, et Tradearea doivent �tre affich�s.
//	Veuillez noter qu'un r�sultat complet avec toutes les cartes pour la fonctionnalit� Pause est affich� avec une fonction distincte.  
//	Table poss�de un constructeur qui accepte un flux istream et construit un objet de type Table � partir du fichier.Player(const istream&, CardFactory*)

class Table {
	Player* joueur1;
	Player* joueur2;
	Deck* deck;
	DiscardPile* discardPile;
	TradeArea* tradeArea;
	bool tour;
public:
	Table(istream&, CardFactory*);
	Table(Player*, Player*, Deck*, DiscardPile*, TradeArea*);
	~Table();
	bool win(std::string&);
	void printHand(bool);
	Player* changerTour();
	Player* getPlayer1();
	Player* getPlayer2();
	Deck* getDeck();
	DiscardPile* getDiscardPile();
	TradeArea* getTradeArea();
	bool getTour();

	friend ostream& operator << (ostream & o, const Table &t) {
		o << "------ JOUEURS ------" << endl;
		o << *(t.joueur1) << endl << *(t.joueur2) << endl << endl;
		o << "------ REBUT ------" << endl;
		o << *(t.discardPile) << endl << endl;
		o << "------ ZONE D'ECHANGE ------" << endl;
		o << *(t.tradeArea) << endl << endl;
		return o;
	}
};
