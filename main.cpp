

#include "Gemstones.h"
#include "Chain.h"
#include "Hand.h"
#include "Player.h"
#include "TradeArea.h"
#include "DiscardPile.h"
#include "Table.h"
#include <stdlib.h> 
#include <fstream>
#include <iostream>


bool estOui(const std::string& str) {
	return ((str == "O") || (str == "o"));
}

bool estUneReponse(const std::string& str) {
	return (estOui(str) || (str == "N") || (str == "n"));
}




int main() {

	std::string reponse;

	
	CardFactory *cf;
	cf = CardFactory::getFactory();

	Deck* d;
	TradeArea* ta;
	DiscardPile* dp;
	Player* p1;
	Player* p2;
	Table* t;


	
	while (reponse != "C" && reponse != "R") {
		std::cout << "Voulez vous (C)ommencer une nouvelle partie, ou (R)eprendre une nouvelle partie?" << endl;
		getline(cin, reponse);
	}
	ifstream saveFile("Saved.txt");
	bool saveExist = saveFile.good();
	if (!saveExist&&reponse=="R")
	{
		std::cout << "Il n'y a pas de partie sauvgarder"<<endl<<endl<<"Nouvelle partie initializer"<<endl;
		reponse = "C";
	}
	if (reponse == "R") {

		ifstream tableSet ("Saved.txt");
		t = new Table(tableSet,cf);
		d = t->getDeck();
		ta = t->getTradeArea();
		dp = t->getDiscardPile();
		p1 = t->getPlayer1();
		p2 = t->getPlayer2();
		
		tableSet.close();
		


	}
	else {
		

		std::cout << endl << endl;

		// SETUP
		d = new Deck();
		ta = new TradeArea();
		dp = new DiscardPile();

		(*d) = cf->getDeck();
		std::string n1, n2;

		std::cout << "Entrer le nom du joueur 1 : " << endl;
		getline(cin, n1);
		std::cout << endl << "Entrer le nom du joueur 2 : " << endl;
		getline(cin, n2);

		p1 = new Player(n1);
		p2 = new Player(n2);

		(*p1).startHand((*d));
		(*p2).startHand((*d));

		t = new Table(p1, p2, d, dp, ta);
		
	}
		
		

		Player * joueurCourant;

		// BOUCLE DE JEU

		while (!(*d).empty()) {
			joueurCourant = t->changerTour();
			std::cout << "---- Au tour de " << joueurCourant->getName() << endl << endl;
			std::cout << *t;

			joueurCourant->drawCard((*d));
			std::cout << "Vous avez tire " << ((joueurCourant->getHand())->derniereCarteAjoutee())->getName() << endl << endl;

			// Le joueur joue les cartes de la zone d'echange

			reponse.empty();

			if (!(*ta).estVide()) {
				std::cout << "Zone d'echange :" << endl;
				std::cout << (*ta);
				std::cout << endl << "Vos chaines :" << endl;
				joueurCourant->printChaines(std::cout);
				std::cout << endl;

				list<Card*>::iterator it = (*ta).getListeCartes().begin();

				while (it != (*ta).getListeCartes().end()) {
					reponse.empty();
					std::cout << "(A)jouter " << (*it)->getName() << " a une de vos chaines, la (J)eter, ou ne (R)ien faire?" << endl;
					getline(cin, reponse);
					if (reponse == "A") {
						bool supp = joueurCourant->playCard((*ta).trade((*(it++))->getName()), true);
					}
					if (reponse == "J") {
						(*dp) += ((*ta).trade((*(it++))->getName()));
					}
					if (reponse == "R") {
						it++;
					}
				}
			}

			// Le joueur joue la carte du haut de sa main

			std::cout << endl << endl << "Votre main est " << *(joueurCourant->getHand()) << endl;
			std::cout << "Vous devez jouer la carte en haut de la main" << endl << endl;

			joueurCourant->playCard((joueurCourant->getHand())->play(), true);

			// Vente automatique des chaines

			joueurCourant->vendreAuto();

			// Le joueur peut jouer une nouvelle carte de sa main s'il le souhaite

			if (joueurCourant->hasCard()) {
				joueurCourant->playCard((joueurCourant->getHand())->play(), false);
			}

			// Vente automatique des chaines

			joueurCourant->vendreAuto();

			reponse.empty();
			std::cout << endl << endl << "Votre main est : " << endl << *(joueurCourant->getHand()) << endl;
			while (!estUneReponse(reponse)) {
				reponse.empty();
				std::cout << "Voulez-vous jeter une des cartes? (O)ui/(N)on" << endl;
				getline(cin, reponse);
			}
			if (estOui(reponse)) {
				bool fait = false;
				int i = 0;
				while ((i < (joueurCourant->getHand())->getSize()) && !fait) {
					reponse = "";
					while (!(estUneReponse(reponse))) {
						std::cout << "Jeter " << *((joueurCourant->getHand()))->show(i) << "? (O)ui/(N)on" << endl;
						getline(cin, reponse);
					}
					if (estOui(reponse)) {
						(*dp) += ((*(joueurCourant->getHand()))[i]);
						fait = true;
					}
					i++;
				}
			}

			// Le joueur tire 3 cartes et les places dans la zone d'échange

			std::cout << endl << endl << "Tirage de 3 cartes du deck pour la zone d'echange" << endl << endl;

			for (int i = 0; i < 3; i++)
			{
				(*ta) += ((*d).draw());
				std::cout << "Carte tiree : ";
				(*ta).afficherDerniere();
			}

			while ((!(*dp).estVide()) && ((*ta).legal((*dp).top()))) {
				std::cout << "Ajoute de la carte " << (*dp).top()->getName() << " du rebut a la zone d'echange" << endl;
				(*ta) += (*dp).pickUp();
			}

			std::cout << endl << endl;

			if (!(*ta).estVide()) {
				std::cout << "Zone d'echange :" << endl;
				std::cout << (*ta);
				std::cout << endl << "Vos chaines :" << endl;
				joueurCourant->printChaines(std::cout);
				std::cout << endl;
				list<Card*>::iterator it = (*ta).getListeCartes().begin();

				while (it != (*ta).getListeCartes().end()) {
					reponse.empty();
					std::cout << "(A)jouter " << (*it)->getName() << " a une de vos chaines ou ne (R)ien faire?" << endl;
					getline(cin, reponse);
					if (reponse == "A") {
						bool supp = joueurCourant->playCard((*ta).trade((*(it++))->getName()), false);
					}
					if (reponse == "R") {
						it++;

					}
				}
			}

			// Le joueur tire 2 cartes

			joueurCourant->drawCard((*d));
			joueurCourant->drawCard((*d));

			// Fin du tour

			std::cout << "Fin du tour de " << joueurCourant->getName() << endl << endl << endl;
			if (d->size()!=0){
				reponse = "";
			std::cout << "Voulez-vous sauvegarder et mettre en pause la partie? (O)ui/(N)on" << endl;
			getline(cin, reponse);
			if (estOui(reponse)) {

				ofstream savingFile;
				savingFile.open("Saved.txt");
				std::cout << savingFile.is_open();

				savingFile << (*d);
				savingFile << endl;


				savingFile << (*ta);

				savingFile << endl;
				(*dp).print(savingFile);

				bool tour = t->getTour();


				savingFile << p1->getName() << " " << p1->getMaxNumChains() << " " << p1->getNumCoins() << endl;
				p1->printHand(savingFile, true);
				savingFile << endl;
				p1->printChaines(savingFile);

				savingFile << p2->getName() << " " << p2->getMaxNumChains() << " " << p2->getNumCoins() << endl;
				p2->printHand(savingFile, true);
				savingFile << endl;
				p2->printChaines(savingFile);


				savingFile << tour;


				savingFile.flush();
				savingFile.close();

				delete t;

				exit(0);
			}
		}

		}

		std::cout << " -- PARTIE TERMINEE -- " << endl;
		std::string gagnant;
		t->win(gagnant);
		std::cout << "Le vainqueur est " << gagnant << endl << endl;
		std::cout << *t;
	


	return 0;
}