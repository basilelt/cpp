#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include <string>
#include "Card.hpp"

class TrainerCard : public Card
{
public:
    TrainerCard();                    /* constructeur par défaut */
    TrainerCard(std::string);         /* constructeur avec paramètres */
    TrainerCard(const TrainerCard &); /* constructeur de copie */
    virtual ~TrainerCard();           /* destructeur */

    virtual TrainerCard &operator=(const TrainerCard &); /* opérateur d'affectation */

    virtual std::string getEnergyType() const;
    virtual void setEnergyType(const std::string &);

    virtual std::ostream &displayInfo(std::ostream &) const override; /* Méthode virtuelle pure */

private:
    std::string energyType;
};

#endif /* TrainerCard_hpp */