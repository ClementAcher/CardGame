#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <algorithm> 
#include <random>
#include <time.h>
#include "Card.h"
#include "Gemstones.h"
#include "Deck.h"

using namespace std;

class CardFactory {
	
public:
	CardFactory();
	CardFactory operator=(const CardFactory&) = delete;
	CardFactory(const CardFactory&) = delete;

	static CardFactory* getFactory();
	Deck getDeck();
	Card* creerCarte(std::string &nom);
	
};
