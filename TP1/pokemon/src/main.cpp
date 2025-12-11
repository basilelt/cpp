#include "headers/card.h"         // [cite: 3]
#include "headers/pokemon_card.h" // [cite: 4]
#include "headers/energy_card.h"  // [cite: 4]
#include "headers/trainer_card.h" // [cite: 5]
#include "headers/player.h"       // [cite: 6]
#include <iostream>               // [cite: 7]
#include <string>                 // [cite: 8]

using namespace std; // [cite: 9]

int main() // [cite: 10]
{
    Player player1("Hadi"); // [cite: 12]

    // Adding cards to Player 1's bench
    player1.addCardToBench(new EnergyCard("Electric"));                             //
    player1.addCardToBench(new EnergyCard("Electric"));                             // [cite: 14]
    player1.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon")); // [cite: 15]

    // Merged lines 15 and 16 for the PokemonCard constructor
    player1.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 2, "thunder bolt", 20, 3, "thunder storm", 30)); // [cite: 15, 16]

    player1.activatePokemonCard(3); //

    // Attaching energy cards (broken across lines 18-19 and 25-26 in source)
    player1.attachEnergyCard(0, 0); // [cite: 18, 25]
    player1.attachEnergyCard(0, 0); // [cite: 19, 26]

    cout << endl;            // [cite: 20]
    player1.displayBench();  //
    cout << endl;            // [cite: 22]
    player1.displayAction(); //

    Player player2("Germain"); // [cite: 24]

    // Adding cards to Player 2's bench
    player2.addCardToBench(new EnergyCard("Grass"));                                  // [cite: 27]
    player2.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon")); // [cite: 28]

    // Merged lines 28 and 29 for the PokemonCard constructor
    player2.addCardToBench(new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 2, "Leech Seed", 15, 3, "Vine Whip", 25)); // [cite: 28, 29]

    player2.activatePokemonCard(2); // [cite: 30]
    player2.attachEnergyCard(0, 0); // [cite: 31]

    cout << endl;            // [cite: 32]
    player2.displayBench();  // [cite: 33]
    cout << endl;            // [cite: 34]
    player2.displayAction(); // [cite: 35]

    // Combat phase
    player1.attack(0, 0, player2, 0); //

    cout << endl;            // [cite: 37]
    player2.displayAction(); // [cite: 38]

    player2.useTrainer(0); //

    cout << endl;            // [cite: 40]
    player2.displayAction(); // [cite: 41]

    return 0; // [cite: 42]
}