
#include "Gemstones.h"
#include <iostream>


const std::string Quartz::nom = "Quartz";
const std::string Hematite::nom = "Hematite";
const std::string Obsidian::nom = "Obsidian";
const std::string Malachite::nom = "Malachite";
const std::string Turquoise::nom = "Turquoise";
const std::string Ruby::nom = "Ruby";
const std::string Amethyst::nom = "Amethyst";
const std::string Emerald::nom = "Emerald";

int Quartz::getCardsPerCoin(int nbcarte)
{
	switch (nbcarte) {
	case 0:
	case 1:
	case 2:
	case 3:
		return 0;
	case 4:
	case 5:
		return 1;
	case 6:
	case 7:
		return 2;
	case 8:
	case 9:
		return 3;
	case 10:
		return 4;
	default:
		return 4;
	}
}

int Hematite::getCardsPerCoin(int nbcarte)
{
	switch (nbcarte) {
	case 0:
	case 1:
	case 2:
		return 0;
	case 3:
	case 4:
	case 5:
		return 1;
	case 6:
	case 7:
		return 2;
	case 8:
		return 3;
	case 9:
	default:
		return 4;
	}
}

int Obsidian::getCardsPerCoin(int nbcarte)
{
	switch (nbcarte) {
	case 0:
	case 1:
	case 2:
		return 0;
	case 3:
	case 4:
	case 5:
		return 1;
	case 6:
	case 7:
		return 2;
	case 8:
		return 3;
	case 9:
	default:
		return 4;
	}
}

int Malachite::getCardsPerCoin(int nbcarte)
{
	switch (nbcarte) {
	case 0:
	case 1:
	case 2:
		return 0;
	case 3:
	case 4:
		return 1;
	case 5:
		return 2;
	case 6:
		return 3;
	case 7:
	default:
		return 4;
	}
}

int Turquoise::getCardsPerCoin(int nbcarte)
{
	switch (nbcarte) {
	case 0:
	case 1:
		return 0;
	case 2:
	case 3:
		return 1;
	case 4:
	case 5:
		return 2;
	case 6:
		return 3;
	case 7:
	default:
		return 4;
	}
}

int Ruby::getCardsPerCoin(int nbcarte)
{
	switch (nbcarte) {
	case 0:
	case 1:
		return 0;
	case 2:
	case 3:
		return 1;
	case 4:
		return 2;
	case 5:
		return 3;
	case 6:
	default:
		return 4;
	}
}

int Amethyst::getCardsPerCoin(int nbcarte)
{
	switch (nbcarte) {
	case 0:
	case 1:
		return 0;
	case 2:
		return 1;
	case 3:
		return 2;
	case 4:
		return 3;
	case 5:
	default:
		return 4;
	}
}

int Emerald::getCardsPerCoin(int nbcarte)
{
	switch (nbcarte) {
	case 0:
	case 1:
		return 0;
	case 2:
		return 2;
	case 3:
		return 3;
	default:
		return 3;
	}
}