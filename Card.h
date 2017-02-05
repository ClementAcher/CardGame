#pragma once

#include <iostream>

//	virtual int getCardsPerCoin(int coins) impl�mentera dans les classes d�riv�es le tableau pour un nombre de cartes 
//	n�cessaires afin de recevoir le nombre correspondant de pi�ces(coins).
//	virtual std::string getName() renvoie le nom complet de la carte(e.g., Ruby).
//	virtual void print(const ostream& out) ins�re le premier caract�re de la carte dans le flux de sortie fourni en argument.
//	Vous devriez cr�er �galement un flux global de l'op�rateur d'insertion pour l'affichage des objets d'une telle classe qui impl�mente 
//	�Virtual Friend Function Idiom� avec la hi�rarchie de la classe.

using namespace std;

class CardFactory;

class Card {
public:
	virtual int getCardsPerCoin(int) = 0;
	virtual std::string getName() = 0;
	virtual void print(ostream&) = 0; 
	friend ostream& operator<<(std::ostream&, Card&);
};