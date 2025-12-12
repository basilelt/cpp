#include "StepGenerator.hpp"
#include <iostream>

/* Constructeur par défaut */
StepGenerator::StepGenerator() : StepGenerator()
{
}

/* Destructeur */
StepGenerator::~StepGenerator()
{
}

/* Surcharge du générateur de séries temporelles */
std::vector<double> StepGenerator::generateTimeSeries(int length) const
{
    std::vector<double> series(length);

    return series;
}
