#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Base.hpp"
#include "Card.hpp"
#include "PokemonCard.hpp"

class Player : public Base
{
public:
    Player();                                                             /* constructeur par défaut */
    Player(std::string, std::vector<Card *>, std::vector<PokemonCard *>); /* constructeur avec paramètres */
    Player(const Player &);                                               /* constructeur de copie */
    virtual ~Player();                                                    /* destructeur */

    virtual Player &operator=(const Player &); /* opérateur d'affectation */

    virtual std::string getPlayerName() const;
    virtual void setPlayerName(const std::string &);
    virtual const std::vector<Card *> &getBenchCards() const;
    virtual void setBenchCards(const std::vector<Card *> &);
    virtual const std::vector<PokemonCard *> &getActionCards() const;
    virtual void setActionCards(const std::vector<PokemonCard *> &);

protected:
    std::string playerName;
    std::vector<Card *> benchCards;
    std::vector<PokemonCard *> actionCards;
};

#endif /* Player_hpp */