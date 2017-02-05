
#include "Deck.h"
#include "CardFactory.h"
#include <sstream>
#include <iterator>

Card* Deck::draw() {
	try
	{
		if (size() > 0) {
			Card* c = this->back();
			this->pop_back();
			return c;
		}
		else {
			throw (EmptyDeck());
		}
	}
	catch (EmptyDeck& e)
	{
		cout << endl << e.what() << endl;
	}
}

Deck::Deck()
{
}
Deck::Deck(istream & is, CardFactory* cf)
{
	
	std::string allCards;

	getline(is,allCards);
	

	istringstream buf(allCards);
	istream_iterator<std::string> beg(buf), end;

	vector<std::string> cards(beg, end);
	for (std::string& nom : cards)
	{
		Card* c = ((*cf).creerCarte(nom));
		if (c != NULL)
			push_back(c);
	}

	

}
