#include "PokemonCard.hpp"
#include <string>
#include <iostream>

/* Constructeur par défaut */
PokemonCard::PokemonCard() : Card(""),
                             pokemonType(""),
                             familyName(""),
                             evolutionLevel(0),
                             maxHP(0),
                             hp(0),
                             energyCost(0),
                             energyCurrent(0),
                             attackDescription(""),
                             attack(0)
{
}

/* Constructeur avec paramètres */
PokemonCard::PokemonCard(std::string _cardName,
                         std::string _pokemonType,
                         std::string _familyName,
                         int _evolutionLevel,
                         int _maxHP,
                         int _hp,
                         std::vector<std::tuple<int, int, std::string, int>> _attacks,
                         int _energyCost,
                         int _energyCurrent,
                         std::string _attackDescription,
                         int _attack) : Card(_cardName),
                                        pokemonType(_pokemonType),
                                        familyName(_familyName),
                                        evolutionLevel(_evolutionLevel),
                                        maxHP(_maxHP),
                                        hp(_hp),
                                        attacks(_attacks),
                                        energyCost(_energyCost),
                                        energyCurrent(_energyCurrent),
                                        attackDescription(_attackDescription),
                                        attack(_attack)
{
}

/* Constructeur de copie */
PokemonCard::PokemonCard(const PokemonCard &pc) : Card(pc),
                                                  pokemonType(pc.pokemonType),
                                                  familyName(pc.familyName),
                                                  evolutionLevel(pc.evolutionLevel),
                                                  maxHP(pc.maxHP),
                                                  hp(pc.hp),
                                                  attacks(pc.attacks),
                                                  energyCost(pc.energyCost),
                                                  energyCurrent(pc.energyCurrent),
                                                  attackDescription(pc.attackDescription),
                                                  attack(pc.attack)
{
}

/* Destructeur */
PokemonCard::~PokemonCard()
{
}

/* Opérateur d'affectation */
PokemonCard &PokemonCard::operator=(const PokemonCard &pc)
{
    if (&pc != this)
    {
        Card::operator=(pc);
        pokemonType = pc.pokemonType;
        familyName = pc.familyName;
        evolutionLevel = pc.evolutionLevel;
        maxHP = pc.maxHP;
        hp = pc.hp;
        attacks = pc.attacks;
        energyCost = pc.energyCost;
        energyCurrent = pc.energyCurrent;
        attackDescription = pc.attackDescription;
        attack = pc.attack;
    }
    return *this;
}

/* Surcharge de l'opérateur d'affichage */
std::ostream &PokemonCard::displayInfo(std::ostream &os) const
{
    os << "PokemonCard: " << cardName << std::endl;
    os << "PokemonType: " << pokemonType << std::endl;
    os << "FamilyName: " << familyName << std::endl;
    os << "EvolutionLevel: " << evolutionLevel << std::endl;
    os << "MaxHP: " << maxHP << std::endl;
    os << "HP: " << hp << std::endl;
    os << "Attacks: " << std::endl;
    for (const auto &attack : attacks)
    {
        os << "(";
        os << std::get<0>(attack) << ", ";
        os << std::get<1>(attack) << ", ";
        os << std::get<2>(attack) << ", ";
        os << std::get<3>(attack) << ") " << std::endl;
    }
    os << "EnergyCost: " << energyCost << std::endl;
    os << "EnergyCurrent: " << energyCurrent << std::endl;
    os << "AttackDescription: " << attackDescription << std::endl;
    os << "Attack: " << attack << std::endl;
    return os;
}
