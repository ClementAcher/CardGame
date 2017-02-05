
#include "TradeArea.h"
#include "CardFactory.h"
#include <sstream>
#include <iterator>


TradeArea & TradeArea::operator+=(Card *c)
{
	listeCartes.push_back(c);
	return *this;
}

bool TradeArea::legal(Card *c)
{
	bool l = false;
	for (auto& it : listeCartes) {
		if (it->getName() == c->getName()) {
			l = true;
		}
	}
	return l;
}

Card * TradeArea::trade(std::string str)
{
	bool supprime = false;
	list<Card*>::iterator it;
	for (it = listeCartes.begin(); it != listeCartes.end(); it ++) {
		if (((*it)->getName() == str)) {
			supprime = true;
			auto c = *it;
			it = listeCartes.erase(it);
			return c;
		}
	}
	if (!supprime) {
		std::cout << "Aucune carte de ce type" << endl;
	}
	return nullptr;
}

int TradeArea::numCards()
{
	return listeCartes.size();
}

bool TradeArea::estVide()
{
	return (listeCartes.size() == 0);
}

void TradeArea::afficherDerniere()
{
	std::cout << *listeCartes.back() << endl;
}

list<Card*>& TradeArea::getListeCartes()
{
	return listeCartes;
}

TradeArea::TradeArea()
{
}
TradeArea::TradeArea(istream & is, CardFactory *cf)
{

	std::string allCards;

	getline(is, allCards);

	istringstream buf(allCards);
	istream_iterator<std::string> beg(buf), end;

	vector<std::string> cards(beg, end);
	for (std::string& nom : cards)
	{
		Card* c = ((*cf).creerCarte(nom));
		if (c!=NULL)
			listeCartes.push_back(c);
	}

}

