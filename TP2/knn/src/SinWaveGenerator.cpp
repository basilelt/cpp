#include "SinWaveGenerator.hpp"
#include <iostream>

/* Constructeur par défaut */
SinWaveGenerator::SinWaveGenerator() : SinWaveGenerator(0.0, 0.0, 0.0)
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

    return series;
}
