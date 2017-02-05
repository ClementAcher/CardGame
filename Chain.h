#pragma once

#ifndef CSI2372_CHAIN_H
#define CSI2372_CHAIN_H

#include <iostream>
#include <vector>
#include <string>
#include "gemstones.h"
#include "CardFactory.h"
#include <typeinfo>

using namespace std;

// EXCEPTION


class IllegalType {
	std::string type_propose, type_voulu;
public:
	IllegalType(std::string p, std::string v) { type_propose = p; type_voulu = v; }
	void affiche() {
		std::cout << "IllegalType" << endl << "Type demande - " << type_voulu << endl;
		std::cout << "Type propose - " << type_propose << endl;
	}
};

class Chain_all {
	char type;
public:
	Chain_all(char);
	Chain_all& add(Card*);
	char getType() { return type; }
	virtual int sell() = 0;
	virtual void print(ostream&) = 0;
	virtual bool vendreAuto() = 0;
	friend ostream& operator<<(ostream&, Chain_all&);
};


template <class T>
class Chain : public vector<T*>, public Chain_all {
public:
	Chain<T>() :
		Chain_all(T::getID()) {};
	virtual int sell() {
		int l = (*this).size();
		if (l == 0) { // Cas qui ne devrait pas arriver
			return 0;
		}
		else {
			return ((*this).back()->getCardsPerCoin(l));
		}
	}
	virtual bool vendreAuto() {
		if ((sell() == 4) && (Chain_all::getType() != 'E')) {
			return true;
		}
		else if ((sell() == 3) && (Chain_all::getType() == 'E')) {
			return true;
		}
		else {
			return false;
		}
	}
	virtual void print(ostream& out) {
		std::string str = ((*this).back())->getName();
		out << str << '\t'<<" ";
		for (auto& it : (*this))
		{
			(*it).print(out);
		}
	}

	Chain& operator+=(Card * c) {
		std::string name = c->getName();
		try
		{
			if (getType() != name.at(0)) {
				IllegalType it(name, typeid(T).name());
				throw (it);
			}
			else {
				(*this).push_back((T*)c);
				return (*this);
			}
		}
		catch (IllegalType it)
		{
			it.affiche();
		}
	}
};

#endif
