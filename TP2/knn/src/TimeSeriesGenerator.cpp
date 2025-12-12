#include "TimeSeriesGenerator.hpp"
#include <iostream>

/* Constructeur par défaut */
TimeSeriesGenerator::TimeSeriesGenerator() : TimeSeriesGenerator(0, 0)
{
}

/* Constructeur avec paramètres */
TimeSeriesGenerator::TimeSeriesGenerator(int _x, int _y) : x(_x), y(_y)
{
}

/* Constructeur de copie */
TimeSeriesGenerator::TimeSeriesGenerator(const TimeSeriesGenerator &p) : TimeSeriesGenerator(p.x, p.y)
{
}

/* Destructeur */
TimeSeriesGenerator::~TimeSeriesGenerator()
{
}

/* Opérateur d'affectation */
TimeSeriesGenerator &TimeSeriesGenerator::operator=(const TimeSeriesGenerator &p)
{
    if (&p != this)
    {
        x = p.x;
        y = p.y;
    }
    return *this;
}

/* Getters et Setters */
int TimeSeriesGenerator::getX() const
{
    return x;
}

int TimeSeriesGenerator::getY() const
{
    return y;
}

void TimeSeriesGenerator::setX(int _x)
{
    x = _x;
}

void TimeSeriesGenerator::setY(int _y)
{
    y = _y;
}

void TimeSeriesGenerator::translate(int dx, int dy)
{
    x += dx;
    y += dy;
}

/* Surcharge de l'opérateur d'affichage */
std::ostream &TimeSeriesGenerator::PrintOn(std::ostream &os) const
{
    os << "TimeSeriesGenerator(";
    os << x << ", " << y << ")";
    return os;
}
