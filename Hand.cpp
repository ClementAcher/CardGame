
#include "Hand.h"
#include "CardFactory.h"
#include <sstream>
#include <iterator>

Hand::Hand() {}

Card * Hand::play()
{
	try {
		if (estVide()) {
			throw (EmptyHand());
		}
		auto c = vec_carte.front();
		vec_carte.erase(vec_carte.begin());
		return(c);
	}
	catch (EmptyHand& e) {
		std::cout << e.what() << endl;
	}
}

Card * Hand::operator[](int i)
{
	try {
		if (estVide()) {
			throw (EmptyHand());
		}
		auto& c = vec_carte[i];
		vec_carte.erase(vec_carte.begin() + i);
		return(c);
	}
	catch (EmptyHand& e) {
		std::cout << e.what() << endl;
	}
}

Card* Hand::show(int i)
{
	return vec_carte[i];
}

int Hand::getSize()
{
	return vec_carte.size();
}

Hand& Hand::operator+=(Card *c)
{
	vec_carte.push_back(c);
	return(*this);
}

Card * Hand::derniereCarteAjoutee()
{
	try
	{
		if (estVide()) {
			throw (EmptyHand());
		}
		else return vec_carte.back();
	}
	catch (EmptyHand& e) {
		std::cout << e.what() << endl;
	}
}

bool Hand::estVide()
{
	return (vec_carte.size() == 0);
}

Card * Hand::top()
{
	try {
		if (estVide()) {
			throw (EmptyHand());
		}
		auto& c = vec_carte.front();
		return(c);
	}
	catch (EmptyHand& e) {
		std::cout << e.what() << endl;
	}
}

Hand::Hand(istream & is, CardFactory * cf)
{
	std::string allCards;

	getline(is, allCards);

	istringstream buf(allCards);
	istream_iterator<std::string> beg(buf), end;

	vector<std::string> cards(beg, end);
	for (std::string& nom : cards)
	{
		std::string nomComplet;
		if (nom == "Q")
		{
			nomComplet = "Quartz";
		}
		else if (nom == "R")
		{
			nomComplet = "Ruby";
		}
		else if (nom == "H")
		{
			nomComplet = "Hematite";
		}
		else if (nom == "O")
		{
			nomComplet = "Obsidian";
		}
		else if (nom == "M")
		{
			nomComplet = "Malachite";
		}
		else if (nom == "A")
		{
			nomComplet = "Amethyst";
		}
		else if (nom == "E")
		{
			nomComplet = "Emerald";
		}
		else if (nom == "T")
		{
			nomComplet = "Turquoise";
		}
		Card* c = ((*cf).creerCarte(nomComplet));
		if (c != NULL)
			vec_carte.push_back(c);
	}
}