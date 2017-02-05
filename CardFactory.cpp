
#include "CardFactory.h"

static CardFactory* instance;


CardFactory* CardFactory::getFactory() {
	
	if (instance == NULL)
	{
		instance = new CardFactory();
	}

	return instance;
}

Card * CardFactory::creerCarte(std::string & nom)
{
	if (nom == "Quartz")
	{
		return (new Quartz);	
	};
	if (nom == "Ruby")
	{
		return (new Ruby);
	}
	if (nom=="Hematite")
	{
		return (new Hematite);
	}
	if (nom == "Obsidian")
	{
		return (new Obsidian);
	}
	if (nom == "Malachite")
	{
		return (new Malachite);
	}
	if (nom == "Amethyst")
	{
		return (new Amethyst);
	}
	if (nom == "Emerald")
	{
		return (new Emerald);
	}
	if (nom == "Turquoise")
	{
		return (new Turquoise);
	}

	else {
		return nullptr;
	}
}

Deck CardFactory::getDeck() {

	Deck d;

	for (int i = 0; i < 20; i++)
	{
		Quartz* q = new Quartz();
		d.push_back(q);

		if (i < 18)
		{
			Hematite* h = new Hematite();
			d.push_back(h);
		}

		if (i < 16)
		{
			Obsidian* o = new Obsidian();
			d.push_back(o);
		}

		if (i < 14)
		{
			Malachite* m = new Malachite();
			d.push_back(m);
		}
		if (i < 12)
		{
			Turquoise* t = new Turquoise();
			d.push_back(t);
		}
		if (i < 10)
		{
			Ruby* r = new Ruby();
			d.push_back(r);
		}
		if (i < 8)
		{
			Amethyst* a = new Amethyst();
			d.push_back(a);
		}
		if (i < 6)
		{
			Emerald* e = new Emerald();
			d.push_back(e);
		}
	}

	srand(unsigned(time(NULL))); // Nécessaire pour un avoir un mélange différent à chaque instance
	random_shuffle(d.begin(), d.end());

	return d;
}
CardFactory::CardFactory()
{
}