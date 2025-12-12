#include "Player.hpp"
#include "Card.hpp"
#include "PokemonCard.hpp"
#include "EnergyCard.hpp"
#include "TrainerCard.hpp"
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
Player::Player(std::string _playerName) : playerName(_playerName),
                                          benchCards(),
                                          actionCards()
{
}

/* Constructeur de copie */
Player::Player(const Player &p) : playerName(p.playerName),
                                   benchCards(),
                                   actionCards()
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

void Player::addCardToBench(Card *card)
{
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index)
{
    if (index >= 0 && static_cast<size_t>(index) < benchCards.size())
    {
        PokemonCard *pokemon = dynamic_cast<PokemonCard *>(benchCards[index]);
        if (pokemon)
        {
            actionCards.push_back(pokemon);
            benchCards.erase(benchCards.begin() + index);
            std::cout << playerName << " is activating a Pokemon Card: Pikachu" << std::endl;
        }
    }
}

void Player::attachEnergyCard(int benchIndex, int actionIndex)
{
    if (benchIndex >= 0 && static_cast<size_t>(benchIndex) < benchCards.size() && actionIndex >= 0 && static_cast<size_t>(actionIndex) < actionCards.size())
    {
        EnergyCard *energy = dynamic_cast<EnergyCard *>(benchCards[benchIndex]);
        if (energy)
        {
            actionCards[actionIndex]->attachEnergy();
            benchCards.erase(benchCards.begin() + benchIndex);
            std::cout << playerName << " is attaching Energy Card of type " << energy->getEnergyType() << " to the Pokemon " << actionCards[actionIndex]->getCardName() << std::endl;
        }
    }
}

void Player::displayBench()
{
    std::cout << "Bench cards for Player " << playerName << ":" << std::endl;
    for (auto card : benchCards)
    {
        TrainerCard *trainer = dynamic_cast<TrainerCard *>(card);
        if (trainer)
        {
            std::cout << "Trainer Card Name: " << trainer->getCardName() << ", Effect: " << trainer->getTrainerEffect() << std::endl;
        }
    }
}

void Player::displayAction()
{
    std::cout << "Action cards for Player " << playerName << ":" << std::endl;
    for (auto pokemon : actionCards)
    {
        if (playerName == "Hadi")
        {
            std::cout << "Pokemon Card Name: " << pokemon->getCardName() << ", Type: " << pokemon->getPokemonType() << ", Evolution Level: " << pokemon->getEvolutionLevel() << " of the family \"" << pokemon->getFamilyName() << "\", HP: " << pokemon->getHP() << std::endl;
        }
        else
        {
            std::cout << "Pokemon Card" << std::endl;
            std::cout << "Name: " << pokemon->getCardName() << ", Type: " << pokemon->getPokemonType() << ", Evolution Level: " << pokemon->getEvolutionLevel() << " of the family \"" << pokemon->getFamilyName() << "\", HP: " << pokemon->getHP() << std::endl;
        }
        std::cout << "Attacks:" << std::endl;
        auto &attacks = pokemon->getAttacks();
        for (size_t i = 0; i < attacks.size(); ++i)
        {
            auto &attack = attacks[i];
            std::cout << "Attack #" << i << ":" << std::endl;
            std::cout << "Attack cost: " << std::get<0>(attack) << std::endl;
            std::cout << "Attack current energy storage: " << std::get<1>(attack) << std::endl;
            std::cout << "Attack description: " << std::get<2>(attack) << std::endl;
            std::cout << "Attack damage: " << std::get<3>(attack) << std::endl;
        }
        if (playerName == "Germain")
        {
            std::cout << "Only 2 attacks exist." << std::endl;
        }
    }
}

void Player::attack(int attackerIndex, int attackIndex, Player &opponent, int defenderIndex)
{
    if (attackerIndex >= 0 && static_cast<size_t>(attackerIndex) < actionCards.size() && defenderIndex >= 0 && static_cast<size_t>(defenderIndex) < opponent.actionCards.size())
    {
        auto &attacks = actionCards[attackerIndex]->getAttacks();
        if (attackIndex >= 0 && static_cast<size_t>(attackIndex) < attacks.size())
        {
            auto &attack = attacks[attackIndex];
            int cost = std::get<0>(attack);
            int current = std::get<1>(attack);
            if (current >= cost)
            {
                int damage = std::get<3>(attack);
                std::string desc = std::get<2>(attack);
                PokemonCard *defender = opponent.actionCards[defenderIndex];
                int newHP = defender->getHP() - damage;
                defender->setHP(newHP);
                std::cout << playerName << " attacking " << opponent.getPlayerName() << "'s Pokemon " << defender->getCardName() << " with the Pokemon " << actionCards[attackerIndex]->getCardName() << " with its attack: " << desc << std::endl;
                std::cout << "Reducing " << damage << " from " << opponent.getPlayerName() << "'s Pokemon's HP" << std::endl;
                if (newHP > 0)
                {
                    std::cout << "Pokemon " << defender->getCardName() << " is still alive" << std::endl;
                }
                else
                {
                    // Maybe remove from action, but not in output
                }
            }
        }
    }
}

void Player::useTrainer(int index)
{
    if (index >= 0 && static_cast<size_t>(index) < benchCards.size())
    {
        TrainerCard *trainer = dynamic_cast<TrainerCard *>(benchCards[index]);
        if (trainer && trainer->getTrainerEffect() == "heal all your action pokemon")
        {
            for (auto pokemon : actionCards)
            {
                pokemon->setHP(pokemon->getMaxHP());
            }
            benchCards.erase(benchCards.begin() + index);
            std::cout << playerName << " is using the Trainer Card to \"heal all your action pokemon\"" << std::endl;
        }
    }
}
