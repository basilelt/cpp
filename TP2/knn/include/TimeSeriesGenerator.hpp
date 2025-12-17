#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include "Base.hpp"
#include <vector>

class TimeSeriesGenerator : public Base
{
public:
    TimeSeriesGenerator();                            /* constructeur par défaut */
    TimeSeriesGenerator(int);                         /* constructeur avec paramètres */
    TimeSeriesGenerator(const TimeSeriesGenerator &); /* constructeur de copie */
    virtual ~TimeSeriesGenerator();                   /* destructeur */

    virtual TimeSeriesGenerator &operator=(const TimeSeriesGenerator &); /* opérateur d'affectation */

    virtual int getSeed() const;
    virtual void setSeed(int);

    virtual std::vector<double> generateTimeSeries(int) const = 0;
    static void printTimeSeries(const std::vector<double> &);

    virtual std::ostream &PrintOn(std::ostream &) const override;

private:
    int seed;
};

#endif /* TimeSeriesGenerator_hpp */