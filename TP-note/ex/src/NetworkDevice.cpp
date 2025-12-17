#include "Point.hpp"
#include <iostream>

/* Constructeur par défaut */
Point::Point() : Point(0, 0)
{
}

/* Constructeur avec paramètres */
Point::Point(int _x, int _y) : x(_x), y(_y)
{
}

/* Constructeur de copie */
Point::Point(const Point &p) : Point(p.x, p.y)
{
}

/* Destructeur */
Point::~Point()
{
}

/* Opérateur d'affectation */
Point &Point::operator=(const Point &p)
{
    if (&p != this)
    {
        x = p.x;
        y = p.y;
    }
    return *this;
}

/* Getters et Setters */
int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(int _x)
{
    x = _x;
}

void Point::setY(int _y)
{
    y = _y;
}

void Point::translate(int dx, int dy)
{
    x += dx;
    y += dy;
}

/* Surcharge de l'opérateur d'affichage */
std::ostream &Point::PrintOn(std::ostream &os) const
{
    os << "Point(";
    os << x << ", " << y << ")";
    return os;
}
