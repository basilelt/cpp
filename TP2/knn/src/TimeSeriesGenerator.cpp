#include "TimeSeriesGenerator.hpp"
#include <iostream>
#include <vector>

/* Constructeur par défaut */
TimeSeriesGenerator::TimeSeriesGenerator() : TimeSeriesGenerator(0)
{
}

/* Constructeur avec paramètres */
TimeSeriesGenerator::TimeSeriesGenerator(int _seed) : seed(_seed)
{
}

/* Constructeur de copie */
TimeSeriesGenerator::TimeSeriesGenerator(const TimeSeriesGenerator &tsg) : TimeSeriesGenerator(tsg.seed)
{
}

/* Destructeur */
TimeSeriesGenerator::~TimeSeriesGenerator()
{
}

/* Opérateur d'affectation */
TimeSeriesGenerator &TimeSeriesGenerator::operator=(const TimeSeriesGenerator &tsg)
{
    if (&tsg != this)
    {
        seed = tsg.seed;
    }
    return *this;
}

/* Getters et Setters */
int TimeSeriesGenerator::getSeed() const
{
    return seed;
}

void TimeSeriesGenerator::setSeed(int _seed)
{
    seed = _seed;
}

/* Méthodes */
void TimeSeriesGenerator::printTimeSeries(const std::vector<double> &timeSeries) const
{
    for (const auto &value : timeSeries)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
