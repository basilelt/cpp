#include "TrainerCard.hpp"
#include <string>
#include <iostream>

/* Constructeur par défaut */
TrainerCard::TrainerCard() : Card("Energy"), energyType("")
{
}

/* Constructeur avec paramètres */
TrainerCard::TrainerCard(std::string _energyType) : Card("Energy"), energyType(_energyType)
{
}

/* Constructeur de copie */
TrainerCard::TrainerCard(const TrainerCard &ec) : Card(ec), energyType(ec.energyType)
{
}

/* Destructeur */
TrainerCard::~TrainerCard()
{
}

/* Opérateur d'affectation */
TrainerCard &TrainerCard::operator=(const TrainerCard &ec)
{
    if (&ec != this)
    {
        Card::operator=(ec);
        energyType = ec.energyType;
    }
    return *this;
}

/* Surcharge de l'opérateur d'affichage */
std::ostream &TrainerCard::displayInfo(std::ostream &os) const
{
    os << "TrainerCard: " << cardName << std::endl;
    os << "EnergyType: " << energyType << std::endl;
    return os;
}

/* Getters et Setters */
std::string TrainerCard::getEnergyType() const
{
    return energyType;
}

void TrainerCard::setEnergyType(const std::string &_energyType)
{
    energyType = _energyType;
}