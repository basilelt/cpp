#include "Card.hpp"
#include <string>
#include <iostream>

/* Constructeur par défaut */
Card::Card() : Card("")
{
}

/* Constructeur avec paramètres */
Card::Card(std::string _cardName) : cardName(_cardName)
{
}

/* Constructeur de copie */
Card::Card(const Card &c) : cardName(c.cardName)
{
}

/* Destructeur */
Card::~Card()
{
}

/* Opérateur d'affectation */
Card &Card::operator=(const Card &c)
{
    if (&c != this)
    {
        cardName = c.cardName;
    }
    return *this;
}

/* Getters et Setters */
std::string Card::getCardName() const
{
    return cardName;
}

void Card::setCardName(const std::string &_cardName)
{
    cardName = _cardName;
}
