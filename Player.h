#pragma once

#pragma once

#include <iostream>
#include <vector>
#include "Chain.h"
 #include "Hand.h"
#include "Card.h"

//Player(std::string&) constructeur qui crée un objet de type Player avec un nom donné.
//std:string getName() obtenir le nom du joueur.
//	int getNumCoins() obtenir le nombre de pièces actuellement détenues par le joueur.
//	Player& operator+=(int) ajoute un nombre de pièces
//	int getMaxNumChains()renvoie 2 ou 3.
//	int getNumChains()renvoie le nombre de chaînes non nulles.
//	Chain& operator[](int i) renvoie la chaîne en position i.
//	void buyThirdChain()ajoute une troisième chaîne vide au joueur pour deux pièces.La fonction réduit le nombre de pièces par deux pour le joueur.Si le joueur n'a pas suffisamment de pièces alors une exception NotEnoughCoins est soulevée. 
//	void printHand(std::ostream&, bool) affiche  la première carte de la main du joueur(avec l'argument false) ou l'ensemble de la main du joueur(avec l'argument true) dans le flux correspondant  ostream. 
//		Ajouter également l'opérateur d'insertion pour afficher un joueur(Player) dans std::ostream.Le nom du joueur, 
//		le nombre de pièces que possède le joueur et chacune des chaînes(2 ou 3, certaines peuvent être vides) doivent être affichés.
//		Hand est affichée à l’aide d’une autre fonction.L'affichage du joueur peut se présenter comme suit :  
//		Jane     3 coins Ruby     R R R R Quartz   Q
//		Player possède un constructeur qui accepte un flux istream et construit un objet de type Player à partir du fichier.Player(const istream&, CardFactory*

// A FAIRE : operator [] mauvais indice? 

using namespace std;
// Exception

class NotEnoughCoins : public exception {
public:
	virtual const char* what() const throw() {
		return "Pas assez de pieces";
	}
};

class MaxChainLimit : public exception {
public:
	virtual const char* what() const throw() {
		return "Deja 3 chaines";
	}
};

class Player {
	std::string nom;
	int nbpieces, nbMaxChaines, nbChaines;
	vector<Chain_all*> vectChaine;
	Hand* hand;
public:
	Player(std::string&);
	Player(istream&, CardFactory*);
	~Player();
	void buyThirdChain();
	void printHand(ostream&, bool);
	void startHand(Deck &);
	void drawCard(Deck &);
	void createNewChain(std::string&);
	void addCardToChain(Card*);
	bool existeChaine(Card *);
	bool playCard(Card *, bool);
	bool hasCard();
	void printChaines(ostream &);
	void vendreAuto();

	Chain_all& operator[](int);
	Player& operator+= (int n) { nbpieces += n; return(*this); }


	std::string getName() { return nom; }
	int getNumCoins() { return nbpieces; }
	int getMaxNumChains() { return nbMaxChaines; }
	int getNumChains() { return nbChaines; }
	Hand* getHand() { return (hand); } // Peut-être à supprimer plus tard

	friend ostream& operator<<(ostream& o, const Player& p) {
		o << p.nom << "\n" << p.nbpieces << " piece(s)" << endl;

		for (auto& ch : p.vectChaine) {
			o << *ch;
		}
		o << endl << endl;
		return o;
	}
};