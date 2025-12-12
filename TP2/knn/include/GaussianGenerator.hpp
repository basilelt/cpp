#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.hpp"

class GaussianGenerator : public TimeSeriesGenerator
{
public:
    GaussianGenerator();                          /* constructeur par défaut */
    GaussianGenerator(int, int);                  /* constructeur avec paramètres */
    GaussianGenerator(const GaussianGenerator &); /* constructeur de copie */
    virtual ~GaussianGenerator();                 /* destructeur */

    virtual GaussianGenerator &operator=(const GaussianGenerator &); /* opérateur d'affectation */

    virtual float getMean() const;
    virtual void setMean(float);
    virtual float getStddev() const;
    virtual void setStddev(float);

    /* Override car ancêtre */
    virtual std::vector<double> generateTimeSeries(int) const override;

private:
    float mean;
    float stddev;
};

#endif /* GaussianGenerator_hpp */