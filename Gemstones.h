#pragma once

#include <iostream>
#include <string>

#include "Card.h"



class Quartz : public Card {
	const static std::string nom;
public:
	virtual int getCardsPerCoin(int);
	virtual std::string getName() { return nom; }
	virtual void print(ostream& out) { out << "Q "; }
	static char getID() { return (nom[0]); }
};

class Hematite : public Card {
	const static std::string nom;
public:
	virtual int getCardsPerCoin(int);
	virtual std::string getName() { return nom; }
	virtual void print(ostream& out) { out << "H "; }
	static char getID() { return (nom[0]); }
};

class Obsidian : public Card {
	const static std::string nom;
public:
	virtual int getCardsPerCoin(int);
	virtual std::string getName() { return nom; }
	virtual void print(ostream& out) { out << "O "; }
	static char getID() { return (nom[0]); }
};

class Malachite : public Card {
	const static std::string nom;
public:
	virtual int getCardsPerCoin(int);
	virtual std::string getName() { return nom; }
	virtual void print(ostream& out) { out << "M "; }
	static char getID() { return (nom[0]); }
};

class Turquoise : public Card {
	const static std::string nom;
public:
	virtual int getCardsPerCoin(int);
	virtual std::string getName() { return nom; }
	virtual void print(ostream& out) { out << "T "; }
	static char getID() { return (nom[0]); }
};

class Ruby : public Card {
	const static std::string nom;
public:
	virtual int getCardsPerCoin(int);
	virtual std::string getName() { return nom; }
	virtual void print(ostream& out) { out << "R "; }
	static char getID() { return (nom[0]); }
};

class Amethyst : public Card {
	const static std::string nom;
public:
	virtual int getCardsPerCoin(int);
	virtual std::string getName() { return nom; }
	virtual void print(ostream& out) { out << "A "; }
	static char getID() { return (nom[0]); }
};

class Emerald : public Card {
	const static std::string nom;
public:
	virtual int getCardsPerCoin(int);
	virtual std::string getName() { return nom; }
	virtual void print(ostream& out) { out << "E "; }
	static char getID() { return (nom[0]); }
};
