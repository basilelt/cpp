#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.hpp"

class StepGenerator : public TimeSeriesGenerator
{
public:
    StepGenerator();                      /* constructeur par défaut */
    virtual ~StepGenerator();             /* destructeur */

    /* Override car ancêtre */
    virtual std::vector<double> generateTimeSeries(int) const override;

    virtual std::ostream &PrintOn(std::ostream &) const override;
};

#endif /* StepGenerator_hpp */