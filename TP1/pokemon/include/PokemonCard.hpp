#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include <string>
#include <vector>
#include <tuple>
#include "Card.hpp"

class PokemonCard : public Card
{
public:
    PokemonCard(); /* constructeur par défaut */
    PokemonCard(std::string,
                std::string,
                std::string,
                int,
                int,
                int,
                std::vector<std::tuple<int, int, std::string, int>>,
                int,
                int,
                std::string,
                int);                 /* constructeur avec paramètres */
    PokemonCard(const PokemonCard &); /* constructeur de copie */
    virtual ~PokemonCard();           /* destructeur */

    virtual PokemonCard &operator=(const PokemonCard &); /* opérateur d'affectation */

    virtual std::ostream &displayInfo(std::ostream &) const override; /* Méthode virtuelle pure */

    virtual std::string getPokemonType() const;
    virtual void setPokemonType(const std::string &);
    virtual std::string getFamilyName() const;
    virtual void setFamilyName(const std::string &);
    virtual int getEvolutionLevel() const;
    virtual void setEvolutionLevel(int);
    virtual int getMaxHP() const;
    virtual void setMaxHP(int);
    virtual int getHP() const;
    virtual void setHP(int);
    virtual const std::vector<std::tuple<int, int, std::string, int>> &getAttacks() const;
    virtual void setAttacks(const std::vector<std::tuple<int, int, std::string, int>> &);
    virtual int getEnergyCost() const;
    virtual void setEnergyCost(int);
    virtual int getEnergyCurrent() const;
    virtual void setEnergyCurrent(int);
    virtual std::string getAttackDescription() const;
    virtual void setAttackDescription(const std::string &);
    virtual int getAttack() const;
    virtual void setAttack(int);

private:
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    std::vector<std::tuple<int, int, std::string, int>> attacks;
    int energyCost;
    int energyCurrent;
    std::string attackDescription;
    int attack;
};

#endif /* PokemonCard_hpp */