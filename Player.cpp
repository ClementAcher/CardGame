
#include "Player.h"
#include "Gemstones.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>

Player::Player(std::string & str)
{
	hand = new Hand();
	nom = str;
	nbpieces = 2;
	nbMaxChaines = 2;
	nbChaines = 0;
}
Player::~Player()
{
	delete hand;
}
Player::Player(istream & is, CardFactory * cf)
{
	std::string getInfo;

	getline(is, getInfo);

	istringstream buf(getInfo);
	istream_iterator<std::string> beg(buf), end;

	vector<std::string> info(beg, end);
	nom = info[0];
	nbpieces = atoi(info[2].c_str());
	nbMaxChaines = atoi(info[1].c_str());



	hand = new Hand(is, cf);

	std::string chainStr;

	getline(is, chainStr);

	int quartNum=0;
	size_t nPosQuartz = chainStr.find(" Q ", 0); 
	while (nPosQuartz != std::string::npos)
	{
		quartNum++;
		nPosQuartz = chainStr.find(" Q ", nPosQuartz + 1);
	}

	int rubyNum=0;
	size_t nPosRuby = chainStr.find(" R ", 0);
	while (nPosRuby != std::string::npos)
	{
		rubyNum++;
		nPosRuby = chainStr.find(" R ", nPosRuby + 1);
	}

	int hematiteNum=0;
	size_t nPosHematite = chainStr.find(" H ", 0); 
	while (nPosHematite != std::string::npos)
	{
		hematiteNum++;
		nPosHematite = chainStr.find(" H ", nPosHematite + 1);
	}

	int obsidianNum=0;
	size_t nPosObsidian = chainStr.find(" O ", 0);
	while (nPosObsidian != std::string::npos)
	{
		obsidianNum++;
		nPosObsidian = chainStr.find(" O ", nPosObsidian + 1);
	}

	int malachiteNum=0;
	size_t nPosMalachite = chainStr.find(" M ", 0);
	while (nPosMalachite != std::string::npos)
	{
		malachiteNum++;
		nPosMalachite = chainStr.find(" M ", nPosMalachite + 1);
	}

	int amethystNum=0;
	size_t nPosAmethyst = chainStr.find(" A ", 0);
	while (nPosAmethyst != std::string::npos)
	{
		amethystNum++;
		nPosAmethyst = chainStr.find(" A ", nPosAmethyst + 1);
	}

	int emeraldNum=0;
	size_t nPosEmerald = chainStr.find(" E ", 0);
	while (nPosEmerald != std::string::npos)
	{
		emeraldNum++;
		nPosEmerald = chainStr.find(" E ", nPosEmerald + 1);
	}

	int turquoiseNum=0;
	size_t nPosTurquoise = chainStr.find(" T ", 0);
	while (nPosTurquoise != std::string::npos)
	{
		turquoiseNum++;
		nPosTurquoise = chainStr.find(" T ", nPosTurquoise + 1);
	}

	
	std::string nom;
	if (quartNum != 0)
	{
		nom = "Q";
		createNewChain(nom);
		for (int i = 0; i < quartNum; i++)
		{
			Quartz* q = new Quartz();
			addCardToChain(q);
		}
	}
	if (rubyNum != 0) {
		nom = "R";
		createNewChain(nom);
		for (int i = 0; i < rubyNum; i++)
		{
			Ruby* r = new Ruby();
			addCardToChain(r);
		}
	}
	if (hematiteNum != 0) {
		nom = "H";
		createNewChain(nom);
		for (int i = 0; i < hematiteNum; i++)
		{
			Hematite* h = new Hematite();
			addCardToChain(h);
		}
	}

	if (obsidianNum != 0) {
		nom = "O";
		createNewChain(nom);
		for (int i = 0; i < obsidianNum; i++)
		{
			Obsidian* o = new Obsidian();
			addCardToChain(o);
		}
	}
	if (malachiteNum != 0) {
		nom = "M";
		createNewChain(nom);
		for (int i = 0; i < malachiteNum; i++)
		{
			Malachite* m = new Malachite();
			addCardToChain(m);
		}
	}
	if (amethystNum != 0) {
		nom = "A";
		createNewChain(nom);
		for (int i = 0; i < amethystNum; i++)
		{
			Amethyst* a = new Amethyst();
			addCardToChain(a);
		}
	}
	if (emeraldNum != 0) {
		nom = "E";
		createNewChain(nom);
		for (int i = 0; i < emeraldNum; i++)
		{
			Emerald* e = new Emerald();
			addCardToChain(e);
		}
	}
	if (turquoiseNum != 0) {
		nom = "T";
		createNewChain(nom);
		for (int i = 0; i < turquoiseNum; i++)
		{
			Turquoise* t = new Turquoise();
			addCardToChain(t);
		}
	}

	nbChaines = vectChaine.size();

}

Chain_all& Player::operator[](int i)
{
	return (*vectChaine[i]);
}

void Player::buyThirdChain()
{
	try
	{
		if (nbpieces < 2) {
			throw(NotEnoughCoins());
		}
		if (nbMaxChaines == 3) {
			throw (MaxChainLimit());
		}
		nbMaxChaines++;
		nbpieces -= 2;
	}
	catch (MaxChainLimit& e)
	{
		std::cout << e.what() << endl;
	}
	catch (NotEnoughCoins& e)
	{
		std::cout << e.what() << endl;
	}
}

void Player::printHand(ostream & o, bool tout)
{
	if (!tout) {
		o << (*hand).top();
	}
	else {
		o << (*hand);
	}
}

void Player::startHand(Deck &d)
{
	for (int i = 0; i < 5; i++)
	{
		(*hand) += d.draw();
	}
}

void Player::drawCard(Deck &d)
{
	(*hand) += d.draw();
}

void Player::createNewChain(std::string& type)
{
	char t = type.at(0);
	if (nbChaines == nbMaxChaines) {
		std::cout << "Nombre max de chaines atteint!" << endl;
	}

	else {
		switch (t)
		{
		case 'Q':
			vectChaine.push_back(new Chain<Quartz>);
			break;
		case 'H':
			vectChaine.push_back(new Chain<Hematite>);
			break;
		case 'O':
			vectChaine.push_back(new Chain<Obsidian>);
			break;
		case 'M':
			vectChaine.push_back(new Chain<Malachite>);
			break;
		case 'T':
			vectChaine.push_back(new Chain<Turquoise>);
			break;
		case 'R':
			vectChaine.push_back(new Chain<Ruby>);
			break;
		case 'A':
			vectChaine.push_back(new Chain<Amethyst>);
			break;
		case 'E':
			vectChaine.push_back(new Chain<Emerald>);
			break;
		}
		nbChaines++;
	}
}

void Player::addCardToChain(Card * c)
{
	bool match = false;
	for (auto it : vectChaine)
	{
		if (((*it).getType()) == c->getName().at(0) && !match) {
			(*it).add(c);
			match = true;
		}
	}
	if (!match) {
		std::cout << "Pas de chaine correspondante" << endl;
	}
}

bool Player::existeChaine(Card * c)
{
	bool match = false;
	for (auto it : vectChaine)
	{
		if (((*it).getType()) == c->getName().at(0)) {
			match = true;
		}
	}
	if (match) {
		std::cout << "Il existe une chaine du type " << c->getName() << endl;
	}
	else {
		std::cout << "Il n'existe pas de chaine du type " << c->getName() << endl;
	}
	return match;
}

bool Player::playCard(Card * c, bool obligatoire)
{
	std::string reponse;
	if (!obligatoire) {
		while ((reponse != "O") && (reponse != "o") && (reponse != "N") && (reponse != "n")) {
			reponse.empty();
			std::cout << "Ajouter une carte " << c->getName() << " a vos chaines? (O)ui/(N)on" << endl;
			if (existeChaine(c)) {
				printChaines(std::cout);
				std::cout << "| (Vous possedez une chaine de ce type. Vous possedez " << (*this).getNumChains() << " sur " << (*this).getMaxNumChains() << " chaines possibles)" << endl << endl;
			}
			else {
				std::cout << "| (Vous ne possedez pas de chaine de ce type. Vous possedez " << (*this).getNumChains() << " sur " << (*this).getMaxNumChains() << " chaines possibles)" << endl << endl;
			}
			getline(cin, reponse);
		}
		if ((reponse == "N") || (reponse == "n")) {
			return false; 
		}
	}
	else {
		std::cout << "Vous devez ajouter une carte " << c->getName() << " a vos chaines" << endl;
	}
	
	if (existeChaine(c)) {
		std::cout << "Carte ajoutee a la chaine du type " << c->getName() << " deja existante" << endl << endl;
		addCardToChain(c);
		std::cout << *this;
		return true;
	}
	else {
		std::string name = c->getName();
		if (getNumChains() < getMaxNumChains()) {
			createNewChain(name);
			addCardToChain(c);
			std::cout << "Nouvelle chaine creee et carte ajoutee" << endl << endl;
			std::cout << *this;
			return true;
		}
		if ((getMaxNumChains() == 2) && (getNumCoins() >= 2)) {
			cin.clear();
			reponse = "";
			while ((reponse != "O") && (reponse != "o") && (reponse != "N") && (reponse != "n")) {
				std::cout << "Acheter une nouvelle chaine? (O)ui/(N)on" << endl;
				getline(cin, reponse);
			}
			if ((reponse == "O") || (reponse == "o")) {
				buyThirdChain();
				createNewChain(name);
				addCardToChain(c);
				std::cout << "Nouvelle chaine achetee et carte ajoutee" << endl << endl;
				std::cout << *this;
				return true;
			}
		}
		std::cout << "Il est necessaire de vendre une chaine" << endl;
		std::cout << *this;
		bool chaineVendue = false;
		while (!chaineVendue) {
			for (auto it = vectChaine.begin(); it != vectChaine.end(); it++) { 
				std::cout << endl << **it << endl;
				cin.clear();
				reponse = "";
				while ((reponse != "O") && (reponse != "o") && (reponse != "N") && (reponse != "n")) {
					reponse = "";
					std::cout << "Voulez vous vendre cette chaine? Vous gagnerez " << (*it)->sell() << " piece(s). (O)ui/(N)on" << endl;
					getline(cin, reponse);
				}
				if ((reponse == "O") || (reponse == "o")) {
					int vente = (*it)->sell();
					(*this) += (*it)->sell();
					vectChaine.erase(it);
					nbChaines--;
					createNewChain(name);
					addCardToChain(c);
					std::cout << "Chaine vendue pour " << vente << " pieces, nouvelle chaine creee et carte ajoutee" << endl;
					std::cout << *this;
					return true;
				}
				reponse = "";
			}
			if (obligatoire) {
				std::cout << endl << "  !!!!! Vous devez vendre une chaine !!!!!" << endl << endl << endl;
				
			}
			else {
				reponse.empty();
				while ((reponse != "O") && (reponse != "o") && (reponse != "N") && (reponse != "n")) {
					reponse.empty();
					std::cout << "Ne pas vendre de chaine, et annuler l'ajout de cette carte? (O)ui/(N)on" << endl;
					getline(cin, reponse);
				}
				if ((reponse == "O") || (reponse == "o")) {
					std::cout << "Ajout annule" << endl;
					return false;
				}
			}
		}
	}
}

bool Player::hasCard()
{
	return (!(*hand).estVide());
}

void Player::printChaines(ostream & o)
{
	for (auto& ch : vectChaine) {
		o << *ch;
	}
	o << endl;
}

void Player::vendreAuto()
{

	if (vectChaine.size() > 0) {
		auto it = vectChaine.begin();
		while (it != vectChaine.end()) {
			if ((*it)->vendreAuto()) {
				int vente = (*it)->sell();
				std::cout << endl << "Vente automatique (taille max) de la chaine " << (*it)->getType() << " pour " << vente << " pieces " << endl << endl;
				(*this) += (*it)->sell();
				it = vectChaine.erase(it);
				nbChaines--;
				printChaines(std::cout);
			}
			else it++;
		}
	}

}

