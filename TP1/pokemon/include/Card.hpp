#ifndef CARD_H
#define CARD_H

#include "Base.hpp"

class Card : public Base
{
public:
    Card();             /* constructeur par défaut */
    Card(std::string);  /* constructeur avec paramètres */
    Card(const Card &); /* constructeur de copie */
    virtual ~Card();    /* destructeur */

    virtual Card &operator=(const Card &); /* opérateur d'affectation */

    virtual std::ostream &diplayInfo(std::ostream &os) const = 0; /* Méthode virtuelle pure */

protected:
    std::string cardName;
};

#endif /* Card_hpp */