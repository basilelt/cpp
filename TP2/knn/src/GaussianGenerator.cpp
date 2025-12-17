#include "GaussianGenerator.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

/* Constructeur par défaut */
GaussianGenerator::GaussianGenerator() : GaussianGenerator(0.0f, 1.0f)
{
    srand(time(NULL));
}

/* Constructeur avec paramètres */
GaussianGenerator::GaussianGenerator(float _mean, float _stddev) : mean(_mean), stddev(_stddev)
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
    static bool hasSpare = false;
    static double spare;

    for (int i = 0; i < length; ++i)
    {
        if (hasSpare)
        {
            series[i] = spare * stddev + mean;
            hasSpare = false;
        }
        else
        {
            double u1 = (double)rand() / RAND_MAX;
            double u2 = (double)rand() / RAND_MAX;
            double r = sqrt(-2.0 * log(u1));
            double theta = 2.0 * M_PI * u2;
            series[i] = r * cos(theta) * stddev + mean;
            spare = r * sin(theta);
            hasSpare = true;
        }
    }

    return series;
}

std::ostream &GaussianGenerator::PrintOn(std::ostream &os) const
{
    os << "GaussianGenerator with mean: " << mean << ", stddev: " << stddev;
    return os;
}
