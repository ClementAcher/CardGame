
#include "Table.h"
#include "CardFactory.h"
#include <sstream>
#include <iterator>


Table::Table(istream & is, CardFactory *cf)
{
	deck = new Deck(is, cf);
	tradeArea = new TradeArea(is, cf);
	discardPile = new DiscardPile(is, cf);
	joueur1 = new Player(is, cf);
	joueur2 = new Player(is, cf);

	std::string tourSTR;

	getline(is, tourSTR);

	istringstream buf(tourSTR);
	istream_iterator<std::string> beg(buf), end;

	vector<std::string> tourVec(beg, end);

	if (!(tourVec.size()==0))
	{
	const char* res = (tourVec[0].c_str());
	if (atoi(res) == 1)
	{
		tour = true;
	}
	else
	{
		tour = false;
	}
	}
}

Table::Table(Player * j1, Player * j2, Deck * d, DiscardPile* dp, TradeArea * ta)
{
	joueur1 = j1;
	joueur2 = j2;
	deck = d;
	discardPile = dp;
	tradeArea = ta;
	tour = true;
}

bool Table::win(std::string & str)
{
	if (deck->empty()) {
		int p1 = joueur1->getNumCoins();
		int p2 = joueur2->getNumCoins();
		if (p1 == p2) {
			str += "Egalite";
			return (true);
		}
		str += (p1 > p2) ? joueur1->getName() : joueur2->getName();
		return (true);
	}
	else {
		return false;
	}
}

void Table::printHand(bool)
{
}

Player* Table::changerTour()
{
	if (tour) {
		tour = !tour;
		return (joueur1);
	}
	else {
		tour = !tour;
		return (joueur2);
	}
}

Player * Table::getPlayer1()
{
	return joueur1;
}

Player * Table::getPlayer2()
{
	return joueur2;
}
Deck * Table::getDeck()
{
	return deck;
}
DiscardPile * Table::getDiscardPile()
{
	return discardPile;
}
TradeArea * Table::getTradeArea()
{
	return tradeArea;
}
Table::~Table()
{
	delete joueur1;
	delete joueur2;
	delete deck;
	delete discardPile;
	delete tradeArea;
}
bool Table::getTour()
{
	return tour;
}