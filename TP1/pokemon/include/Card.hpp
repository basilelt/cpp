#ifndef CARD_H
#define CARD_H

#include <string>
#include "Base.hpp"

class Card : public Base
{
public:
    Card();             /* constructeur par défaut */
    Card(std::string);  /* constructeur avec paramètres */
    Card(const Card &); /* constructeur de copie */
    virtual ~Card();    /* destructeur */

    virtual Card &operator=(const Card &); /* opérateur d'affectation */

    virtual std::ostream &displayInfo(std::ostream &) const = 0; /* Méthode virtuelle pure */

    virtual std::string getCardName() const;
    virtual void setCardName(const std::string &);

protected:
    std::string cardName;
};

#endif /* Card_hpp */