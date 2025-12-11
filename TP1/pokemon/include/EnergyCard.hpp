#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include <string>
#include "Card.hpp"

class EnergyCard : public Card
{
public:
    EnergyCard();                   /* constructeur par défaut */
    EnergyCard(std::string);        /* constructeur avec paramètres */
    EnergyCard(const EnergyCard &); /* constructeur de copie */
    virtual ~EnergyCard();          /* destructeur */

    virtual EnergyCard &operator=(const EnergyCard &); /* opérateur d'affectation */

    virtual std::ostream &displayInfo(std::ostream &) const override; /* Méthode virtuelle pure */

    virtual std::string getEnergyType() const;
    virtual void setEnergyType(const std::string &);

private:
    std::string energyType;
};

#endif /* EnergyCard_hpp */