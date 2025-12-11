#include "Card.hpp"
#include <iostream>

/* Constructeur par défaut */
Card::Card() : Card(0, 0)
{
}

/* Constructeur avec paramètres */
Card::Card(int _x, int _y) : x(_x), y(_y)
{
}

/* Constructeur de copie */
Card::Card(const Card &p) : Card(p.x, p.y)
{
}

/* Destructeur */
Card::~Card()
{
}

/* Opérateur d'affectation */
Card &Card::operator=(const Card &p)
{
    if (&p != this)
    {
        x = p.x;
        y = p.y;
    }
    return *this;
}

/* Surcharge de l'opérateur d'affichage */
std::ostream &Card::PrintOn(std::ostream &os) const
{
    os << "Card(";
    os << x << ", " << y << ")";
    return os;
}
