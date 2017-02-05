#pragma once

#include <iostream>

//	virtual int getCardsPerCoin(int coins) implémentera dans les classes dérivées le tableau pour un nombre de cartes 
//	nécessaires afin de recevoir le nombre correspondant de pièces(coins).
//	virtual std::string getName() renvoie le nom complet de la carte(e.g., Ruby).
//	virtual void print(const ostream& out) insère le premier caractère de la carte dans le flux de sortie fourni en argument.
//	Vous devriez créer également un flux global de l'opérateur d'insertion pour l'affichage des objets d'une telle classe qui implémente 
//	“Virtual Friend Function Idiom” avec la hiérarchie de la classe.

using namespace std;

class CardFactory;

class Card {
public:
	virtual int getCardsPerCoin(int) = 0;
	virtual std::string getName() = 0;
	virtual void print(ostream&) = 0; 
	friend ostream& operator<<(std::ostream&, Card&);
};