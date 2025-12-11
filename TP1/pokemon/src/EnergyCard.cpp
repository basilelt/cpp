#include "EnergyCard.hpp"
#include <string>
#include <iostream>

/* Constructeur par défaut */
EnergyCard::EnergyCard() : Card("Energy"), energyType("")
{
}

/* Constructeur avec paramètres */
EnergyCard::EnergyCard(std::string _energyType) : Card("Energy"), energyType(_energyType)
{
}

/* Constructeur de copie */
EnergyCard::EnergyCard(const EnergyCard &ec) : Card(ec), energyType(ec.energyType)
{
}

/* Destructeur */
EnergyCard::~EnergyCard()
{
}

/* Opérateur d'affectation */
EnergyCard &EnergyCard::operator=(const EnergyCard &ec)
{
    if (&ec != this)
    {
        Card::operator=(ec);
        energyType = ec.energyType;
    }
    return *this;
}

/* Surcharge de l'opérateur d'affichage */
std::ostream &EnergyCard::displayInfo(std::ostream &os) const
{
    os << "EnergyCard: " << cardName << std::endl;
    os << "EnergyType: " << energyType << std::endl;
    return os;
}

/* Getters et Setters */
std::string EnergyCard::getEnergyType() const
{
    return energyType;
}

void EnergyCard::setEnergyType(const std::string &_energyType)
{
    energyType = _energyType;
}
