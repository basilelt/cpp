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

    virtual std::ostream &displayInfo(std::ostream &os) const override; /* Méthode virtuelle pure */

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