#include "SinWaveGenerator.hpp"
#include <iostream>
#include <cmath>

/* Constructeur par défaut */
SinWaveGenerator::SinWaveGenerator() : SinWaveGenerator(1.0, 0.1, 0.0)
{
}

/* Constructeur avec paramètres */
SinWaveGenerator::SinWaveGenerator(float _amplitude,
                                   float _frequency,
                                   float _phase) : amplitude(_amplitude),
                                                   frequency(_frequency),
                                                   phase(_phase)
{
}

/* Constructeur de copie */
SinWaveGenerator::SinWaveGenerator(const SinWaveGenerator &swg) : SinWaveGenerator(swg.amplitude,
                                                                                   swg.frequency,
                                                                                   swg.phase)
{
}

/* Destructeur */
SinWaveGenerator::~SinWaveGenerator()
{
}

/* Opérateur d'affectation */
SinWaveGenerator &SinWaveGenerator::operator=(const SinWaveGenerator &swg)
{
    if (&swg != this)
    {
        TimeSeriesGenerator::operator=(swg);
        amplitude = swg.amplitude;
        frequency = swg.frequency;
        phase = swg.phase;
    }
    return *this;
}

/* Getters et Setters */
float SinWaveGenerator::getAmplitude() const
{
    return amplitude;
}

float SinWaveGenerator::getFrequency() const
{
    return frequency;
}

float SinWaveGenerator::getPhase() const
{
    return phase;
}

void SinWaveGenerator::setAmplitude(float _amplitude)
{
    amplitude = _amplitude;
}

void SinWaveGenerator::setFrequency(float _frequency)
{
    frequency = _frequency;
}

void SinWaveGenerator::setPhase(float _phase)
{
    phase = _phase;
}

/* Surcharge du générateur de séries temporelles */
std::vector<double> SinWaveGenerator::generateTimeSeries(int length) const
{
    std::vector<double> series(length);
    for (int i = 0; i < length; ++i)
    {
        series[i] = amplitude * sin(frequency * i + phase);
    }
    return series;
}

std::ostream &SinWaveGenerator::PrintOn(std::ostream &os) const
{
    os << "SinWaveGenerator with amplitude: " << amplitude << ", frequency: " << frequency << ", phase: " << phase;
    return os;
}
