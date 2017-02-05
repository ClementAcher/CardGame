
#include "Chain.h"

Chain_all::Chain_all(char str) : type(str)
{
}

ostream & operator << (ostream & out, Chain_all &c) {
	c.print(out);
	return(out);
}

Chain_all & Chain_all::add(Card* card)
{
	char c = card->getName()[0];
	if (c == 'Q') {
		Chain<Quartz>* chain = (Chain<Quartz>*)(this);
		*chain += card;
	}
	else if (c == 'H') {
		Chain<Hematite>* chain = (Chain<Hematite>*)(this);
		*chain += card;
	}
	else if (c == 'O') {
		Chain<Obsidian>* chain = (Chain<Obsidian>*)(this);
		*chain += card;
	}
	else if (c == 'M') {
		Chain<Malachite>* chain = (Chain<Malachite>*)(this);
		*chain += card;
	}
	else if (c == 'T') {
		Chain<Turquoise>* chain = (Chain<Turquoise>*)(this);
		*chain += card;
	}
	else if (c == 'R') {
		Chain<Ruby>* chain = (Chain<Ruby>*)(this);
		*chain += card;
	}
	else if (c == 'Q') {
		Chain<Quartz>* chain = (Chain<Quartz>*)(this);
		*chain += card;
	}
	else if (c == 'E') {
		Chain<Emerald>* chain = (Chain<Emerald>*)(this);
		*chain += card;
	}
	if (c == 'A') {
		Chain<Amethyst>* chain = (Chain<Amethyst>*)(this);
		*chain += card;
	}
	return *this;
}

