#include "Player.hpp"
#include "Card.hpp"
#include "PokemonCard.hpp"
#include <vector>
#include <string>
#include <iostream>

/* Constructeur par défaut */
Player::Player() : playerName(""),
                   benchCards(),
                   actionCards()
{
}

/* Constructeur avec paramètres */
Player::Player(std::string _playerName,
               std::vector<Card *> _benchCards,
               std::vector<PokemonCard *> _actionCards) : playerName(_playerName),
                                                          benchCards(_benchCards),
                                                          actionCards(_actionCards)
{
}

/* Constructeur de copie */
Player::Player(const Player &c) : playerName(c.playerName)
{
}

/* Destructeur */
Player::~Player()
{
}

/* Opérateur d'affectation */
Player &Player::operator=(const Player &c)
{
    if (&c != this)
    {
        playerName = c.playerName;
    }
    return *this;
}

/* Getters et Setters */
std::string Player::getPlayerName() const
{
    return playerName;
}

void Player::setPlayerName(const std::string &_playerName)
{
    playerName = _playerName;
}

const std::vector<Card *> &Player::getBenchCards() const
{
    return benchCards;
}

void Player::setBenchCards(const std::vector<Card *> &_benchCards)
{
    benchCards = _benchCards;
}

const std::vector<PokemonCard *> &Player::getActionCards() const
{
    return actionCards;
}

void Player::setActionCards(const std::vector<PokemonCard *> &_actionCards)
{
    actionCards = _actionCards;
}
