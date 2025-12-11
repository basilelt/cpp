#include "TrainerCard.hpp"
#include <string>
#include <iostream>

/* Constructeur par défaut */
TrainerCard::TrainerCard() : Card(""), trainerEffect("")
{
}

/* Constructeur avec paramètres */
TrainerCard::TrainerCard(std::string _trainerName, std::string _trainerEffect) : Card(_trainerName),
                                                                                 trainerEffect(_trainerEffect)
{
}

/* Constructeur de copie */
TrainerCard::TrainerCard(const TrainerCard &ec) : Card(ec), trainerEffect(ec.trainerEffect)
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
        trainerEffect = ec.trainerEffect;
    }
    return *this;
}

/* Surcharge de l'opérateur d'affichage */
std::ostream &TrainerCard::displayInfo(std::ostream &os) const
{
    os << "TrainerCard: " << cardName << std::endl;
    os << "TrainerEffect: " << trainerEffect << std::endl;
    return os;
}

/* Getters et Setters */
std::string TrainerCard::getTrainerEffect() const
{
    return trainerEffect;
}

void TrainerCard::setTrainerEffect(const std::string &_trainerEffect)
{
    trainerEffect = _trainerEffect;
}