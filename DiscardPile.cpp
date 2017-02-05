
#include "DiscardPile.h"
#include "CardFactory.h"
#include <sstream>
#include <iterator>

DiscardPile::DiscardPile()
{
}

DiscardPile & DiscardPile::operator+=(Card * c)
{
	(*this).push_back(c);
	return *this;
}

bool DiscardPile::estVide()
{
	return ((*this).size() == 0);
}

Card * DiscardPile::pickUp()
{
	if (estVide()) {
		cout << "Pile vide" << endl;
		return nullptr;
	}
	else {
		auto c = back();
		pop_back();
		return c;
	}
}

Card * DiscardPile::top()
{
	return back();
}

DiscardPile::DiscardPile(istream & is, CardFactory *cf )
{
	std::string allCards;

	getline(is, allCards);


	istringstream buf(allCards);
	istream_iterator<std::string> beg(buf), end;

	vector<std::string> cards(beg, end);
	for (auto& nom : cards)
	{
		Card* c = ((*cf).creerCarte(nom));
		if (c != NULL)
			push_back(c);
	}
}

void DiscardPile::print(std::ostream & o)
{
	if (estVide()) {
		o << "Rebut vide" << endl;
	}
	else {
		o << (top())->getName() << endl;
	}
}