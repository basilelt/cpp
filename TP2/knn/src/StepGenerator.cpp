#include "StepGenerator.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/* Constructeur par défaut */
StepGenerator::StepGenerator() : TimeSeriesGenerator(0)
{
    srand(time(NULL));
}

/* Destructeur */
StepGenerator::~StepGenerator()
{
}

/* Surcharge du générateur de séries temporelles */
std::vector<double> StepGenerator::generateTimeSeries(int length) const
{
    std::vector<double> series(length);
    if (length > 0)
    {
        series[0] = 0.0;
        for (int i = 1; i < length; ++i)
        {
            if ((double)rand() / RAND_MAX < 0.5)
            {
                series[i] = series[i - 1];
            }
            else
            {
                series[i] = rand() % 101; // 0 to 100
            }
        }
    }
    return series;
}

std::ostream &StepGenerator::PrintOn(std::ostream &os) const
{
    os << "StepGenerator";
    return os;
}
