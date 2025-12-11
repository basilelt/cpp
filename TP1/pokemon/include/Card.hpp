#ifndef CARD_H
#define CARD_H

#include "Base.hpp"

class Card : public Base
{
public:
    Card();             /* constructeur par défaut */
    Card(int, int);     /* constructeur avec paramètres */
    Card(const Card &); /* constructeur de copie */
    virtual ~Card();    /* destructeur */

    virtual Card &operator=(const Card &); /* opérateur d'affectation */

    virtual int getX() const;
    virtual int getY() const;
    virtual void setX(int);
    virtual void setY(int);
    virtual void translate(int, int);

    /* Override car ancêtre */
    virtual std::ostream &PrintOn(std::ostream &os) const override;

private:
    int x, y;
};

#endif /* Point_hpp */