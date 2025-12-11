#ifndef POINT_H
#define POINT_H

#include "Base.hpp"

class Point : public Base
{
public:
    Point();              /* constructeur par défaut */
    Point(int, int);      /* constructeur avec paramètres */
    Point(const Point &); /* constructeur de copie */
    virtual ~Point();     /* destructeur */

    virtual Point &operator=(const Point &); /* opérateur d'affectation */

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

#endif /* Point_hpp */