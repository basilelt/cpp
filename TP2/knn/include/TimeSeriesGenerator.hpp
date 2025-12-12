#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include "Base.hpp"

class TimeSeriesGenerator : public Base
{
public:
    TimeSeriesGenerator();              /* constructeur par défaut */
    TimeSeriesGenerator(int, int);      /* constructeur avec paramètres */
    TimeSeriesGenerator(const TimeSeriesGenerator &); /* constructeur de copie */
    virtual ~TimeSeriesGenerator();     /* destructeur */

    virtual TimeSeriesGenerator &operator=(const TimeSeriesGenerator &); /* opérateur d'affectation */

    virtual int getX() const;
    virtual int getY() const;
    virtual void setX(int);
    virtual void setY(int);
    virtual void translate(int, int);

    /* Override car ancêtre */
    virtual std::ostream &PrintOn(std::ostream &) const override;

private:
    int x, y;
};

#endif /* TimeSeriesGenerator_hpp */