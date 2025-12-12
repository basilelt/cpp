#ifndef SinWaveGenerator_H
#define SinWaveGenerator_H

#include "TimeSeriesGenerator.hpp"

class SinWaveGenerator : public TimeSeriesGenerator
{
public:
    SinWaveGenerator();                         /* constructeur par défaut */
    SinWaveGenerator(float, float, float);      /* constructeur avec paramètres */
    SinWaveGenerator(const SinWaveGenerator &); /* constructeur de copie */
    virtual ~SinWaveGenerator();                /* destructeur */

    virtual SinWaveGenerator &operator=(const SinWaveGenerator &); /* opérateur d'affectation */

    virtual float getAmplitude() const;
    virtual float getFrequency() const;
    virtual float getPhase() const;
    virtual void setAmplitude(float);
    virtual void setFrequency(float);
    virtual void setPhase(float);

    /* Override car ancêtre */
    virtual std::vector<double> generateTimeSeries(int) const override;

private:
    float amplitude;
    float frequency;
    float phase;
};

#endif /* SinWaveGenerator_hpp */