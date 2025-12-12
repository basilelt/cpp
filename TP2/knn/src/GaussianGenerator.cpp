#include "GaussianGenerator.hpp"
#include <iostream>

/* Constructeur par défaut */
GaussianGenerator::GaussianGenerator() : GaussianGenerator(0, 0)
{
}

/* Constructeur avec paramètres */
GaussianGenerator::GaussianGenerator(int _mean, int _stddev) : mean(_mean), stddev(_stddev)
{
}

/* Constructeur de copie */
GaussianGenerator::GaussianGenerator(const GaussianGenerator &gg) : GaussianGenerator(gg.mean, gg.stddev)
{
}

/* Destructeur */
GaussianGenerator::~GaussianGenerator()
{
}

/* Opérateur d'affectation */
GaussianGenerator &GaussianGenerator::operator=(const GaussianGenerator &gg)
{
    if (&gg != this)
    {
        mean = gg.mean;
        stddev = gg.stddev;
    }
    return *this;
}

/* Getters et Setters */
float GaussianGenerator::getMean() const
{
    return mean;
}

void GaussianGenerator::setMean(float _mean)
{
    mean = _mean;
}

float GaussianGenerator::getStddev() const
{
    return stddev;
}

void GaussianGenerator::setStddev(float _stddev)
{
    stddev = _stddev;
}

/* Surcharge du générateur de séries temporelles */
std::vector<double> GaussianGenerator::generateTimeSeries(int length) const
{
    std::vector<double> series(length);

    return series;
}
