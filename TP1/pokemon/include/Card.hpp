#ifndef CARD_H
#define CARD_H

#include "Base.hpp"

class Card : public Base
{
public:
    virtual std::ostream &diplayInfo(std::ostream &os) const = 0; /* Méthode virtuelle pure */

protected:
    std::string cardName;
};

#endif /* Card_hpp */