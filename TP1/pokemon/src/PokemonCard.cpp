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

/* Constructeur alternatif avec attaques séparées */
PokemonCard::PokemonCard(std::string _cardName,
                         std::string _pokemonType,
                         std::string _familyName,
                         int _evolutionLevel,
                         int _maxHP,
                         int _hp,
                         std::string _attack1Desc,
                         int _attack1Damage,
                         int _attack2Cost,
                         std::string _attack2Desc,
                         int _attack2Damage) : Card(_cardName),
                                              pokemonType(_pokemonType),
                                              familyName(_familyName),
                                              evolutionLevel(_evolutionLevel),
                                              maxHP(_maxHP),
                                              hp(_hp),
                                              attacks({std::make_tuple(2, 0, _attack1Desc, _attack1Damage),
                                                       std::make_tuple(_attack2Cost, 0, _attack2Desc, _attack2Damage)}),
                                              energyCost(0),
                                              energyCurrent(0),
                                              attackDescription(""),
                                              attack(0)
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

/* Getters and setters */
std::string PokemonCard::getPokemonType() const
{
    return pokemonType;
}

void PokemonCard::setPokemonType(const std::string &_pokemonType)
{
    pokemonType = _pokemonType;
}

std::string PokemonCard::getFamilyName() const
{
    return familyName;
}

void PokemonCard::setFamilyName(const std::string &_familyName)
{
    familyName = _familyName;
}

int PokemonCard::getEvolutionLevel() const
{
    return evolutionLevel;
}

void PokemonCard::setEvolutionLevel(int _evolutionLevel)
{
    evolutionLevel = _evolutionLevel;
}

int PokemonCard::getMaxHP() const
{
    return maxHP;
}

void PokemonCard::setMaxHP(int _maxHP)
{
    maxHP = _maxHP;
}

int PokemonCard::getHP() const
{
    return hp;
}

void PokemonCard::setHP(int _hp)
{
    hp = _hp;
}

const std::vector<std::tuple<int, int, std::string, int>> &PokemonCard::getAttacks() const
{
    return attacks;
}

void PokemonCard::setAttacks(const std::vector<std::tuple<int, int, std::string, int>> &_attacks)
{
    attacks = _attacks;
}

int PokemonCard::getEnergyCost() const
{
    return energyCost;
}

void PokemonCard::setEnergyCost(int _energyCost)
{
    energyCost = _energyCost;
}

int PokemonCard::getEnergyCurrent() const
{
    return energyCurrent;
}

void PokemonCard::setEnergyCurrent(int _energyCurrent)
{
    energyCurrent = _energyCurrent;
}

std::string PokemonCard::getAttackDescription() const
{
    return attackDescription;
}

void PokemonCard::setAttackDescription(const std::string &_attackDescription)
{
    attackDescription = _attackDescription;
}

int PokemonCard::getAttack() const
{
    return attack;
}

void PokemonCard::setAttack(int _attack)
{
    attack = _attack;
}

void PokemonCard::attachEnergy()
{
    for (auto &attack : attacks)
    {
        std::get<1>(attack)++;
    }
    energyCurrent++;
}
