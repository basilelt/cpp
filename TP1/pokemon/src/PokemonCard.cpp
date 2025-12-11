#include "PokemonCard.hpp"
#include <string>
#include <iostream>

/* Constructeur par défaut */
PokemonCard::PokemonCard() : cardName("")
{
}

/* Constructeur avec paramètres */
PokemonCard::PokemonCard(std::string _cardName) : cardName(_cardName)
{
}

/* Constructeur de copie */
PokemonCard::PokemonCard(const PokemonCard &c) : cardName(c.cardName)
{
}

/* Destructeur */
PokemonCard::~PokemonCard()
{
}

/* Opérateur d'affectation */
PokemonCard &PokemonCard::operator=(const PokemonCard &c)
{
    if (&c != this)
    {
        cardName = c.cardName;
    }
    return *this;
}

/* Surcharge de l'opérateur d'affichage */
std::ostream &PokemonCard::displayInfo(std::ostream &os) const
{
    os << "PokemonCard: " << cardName;
    return os;
}
