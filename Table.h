#pragma once

#include <string>
#include <iostream>
#include "Player.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "CardFactory.h"

//  Table permettra de gérer tous les composants du jeu.Elle tiendra deux objets de type Player, Deck et DiscardPile, ainsi que TradeArea.
//  bool win(std::string& renvoie true si le joueur a gagné.Le nom du joueur est transmis par référence(en argument).
//  La condition de gagner est que toutes les cartes de Deck doivent avoir été reprises et alors le joueur avec le plus de pièces gagne.
//	void printHand(bool) affiche la première carte de la main du joueur(avec l’argument false) ou l'ensemble de la main du joueur  (avec argument true). 
//	Ajouter également l'opérateur d'insertion pour afficher Table dans std::ostream. Les deux joueurs, la pile au rebut, et Tradearea doivent être affichés.
//	Veuillez noter qu'un résultat complet avec toutes les cartes pour la fonctionnalité Pause est affiché avec une fonction distincte.  
//	Table possède un constructeur qui accepte un flux istream et construit un objet de type Table à partir du fichier.Player(const istream&, CardFactory*)

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
