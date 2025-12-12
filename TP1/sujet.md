## Pokemon Trading Card Game [cite: 121]

Dans le cadre de cet exercice de travaux pratiques, vous allez mettre en œuvre le jeu de cartes Pokémon en C++. [cite: 122] Utilisez des classes, des fonctions et des boucles pour créer une simulation précise des mécanismes du jeu. [cite: 122] Assurez-vous de suivre attentivement les consignes pour produire une solution conforme. [cite: 123]

-----

### Question 1 [cite: 134]

Commencez par implémenter une classe de base `Card` qui aura un élément appelé `cardName` de type chaîne de caractères (string). [cite: 135] Cette classe comportera une fonction virtuelle pure appelée `displayInfo` de type void. [cite: 136]

### Question 2 [cite: 137]

Implémentez maintenant la classe `PokemonCard` qui hérite de la classe `Card`. [cite: 138] Cette classe devrait avoir les éléments suivants :

  * Le nom de Pokemon sera affecté à `cardName` dans la classe de Base (`Card`) [cite: 139]
  * `pokemonType` (chaîne de caractères) [cite: 140]
  * `familyName` (chaîne de caractères) [cite: 141]
  * `evolutionLevel` (entier) [cite: 142]
  * `maxHP` (entier) [cite: 143]
  * `hp` (entier) [cite: 144]
  * `attacks` (vector tuple\<int, int, string, int\>) contenant uniquement deux attaques. [cite: 145] Chaque attaque est un tuple comprenant :
      * Coût en énergie (entier) [cite: 146]
      * Coût en énergie actuel (entier) [cite: 147]
      * Description de l'attaque (chaîne de caractères) [cite: 148]
      * Dégâts de l'attaque (entier) [cite: 149]

### Question 3 [cite: 150]

Implémentez maintenant la classe `EnergyCard` qui hérite de la classe `Card`. [cite: 151] Cette classe devrait avoir les éléments suivants :

  * Le nom de la carte sera toujours par defaut "Energy" pour `cardName` [cite: 152]
  * `energyType` (chaîne de caractères) [cite: 153]

### Question 4 [cite: 154]

Implémentez maintenant la classe `TrainerCard` qui hérite de la classe `Card`. [cite: 155] Cette classe devrait avoir les éléments suivants :

  * Le nom du Trainer sera passe au constructeur pour `cardName` [cite: 156]
  * `trainerEffect` (chaîne de caractères) [cite: 157]
  * Pour l'instant, le seul effet que c'est demandé à implementer est "heal all your action pokemon" qui remet les HP de tous les Pokemon en action au maximum. [cite: 158]

### Question 5 [cite: 159]

Implémentez maintenant la classe `Player` avec les attributs suivants : [cite: 160]

  * `playerName` (string) [cite: 161]
  * `benchCards` (`vector<Card*>`) un vecteur de pointeurs vers des éléments `Card`; c'est le deck des cartes en réserve. [cite: 162]
  * `actionCards` (`vector<PokemonCard*>`) un vecteur de pointeurs vers des éléments `PokemonCard`; c'est le deck des cartes d'action Pokémon. [cite: 163]

-----

### Question 6 [cite: 166]

Maintenant, l'objectif est d'adapter toutes les classes précédentes (ajouter des attributs, des fonctions, etc.) de manière à ce que ce code produise la sortie requise. [cite: 167]

```cpp
#include "headers/card.h"          // [cite: 168]
#include "headers/pokemon_card.h"  // [cite: 169]
#include "headers/energy_card.h"   // [cite: 169]
#include "headers/trainer_card.h"  // [cite: 170]
#include "headers/player.h"        // [cite: 171]
#include <iostream>                // [cite: 172]
#include <string>                  // [cite: 173]
using namespace std;               // [cite: 174]

int main()                         // [cite: 175]
{
    Player player1("Hadi");        // [cite: 177]
    player1.addCardToBench (new EnergyCard("Electric")); // [cite: 178]
    player1.addCardToBench (new EnergyCard ("Electric")); // [cite: 179]
    player1.addCardToBench (new TrainerCard ("Ash", "heal all your action pokemon")); // [cite: 180]
    player1.addCardToBench (new PokemonCard ("Pikachu", "Electric", "Pikachu", 2, 100, 2, "thunder bolt", 20, 3, "thunder storm", 30)); // [cite: 180, 181]
    player1.activatePokemonCard (3); // [cite: 182]
    player1.attachEnergyCard (0, 0); // [cite: 183, 190]
    player1.attachEnergyCard (0, 0); // [cite: 184, 191]
    cout << endl; // [cite: 185]
    player1.displayBench(); // [cite: 186]
    cout << endl; // [cite: 187]
    player1.displayAction(); // [cite: 188]
    
    Player player2("Germain"); // [cite: 189]
    player2.addCardToBench (new EnergyCard("Grass")); // [cite: 192]
    player2.addCardToBench (new TrainerCard("Brock", "heal all your action pokemon")); // [cite: 193]
    player2.addCardToBench (new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 2, "Leech Seed", 15, 3, "Vine Whip", 25)); // [cite: 193, 194]
    player2.activatePokemonCard (2); // [cite: 195]
    player2.attachEnergyCard (0, 0); // [cite: 196]
    
    cout << endl; // [cite: 197]
    player2.displayBench(); // [cite: 198]
    cout << endl; // [cite: 199]
    player2.displayAction(); // [cite: 200]
    
    player1.attack (0, 0, player2, 0); // [cite: 201]
    cout << endl; // [cite: 202]
    player2.displayAction(); // [cite: 203]
    player2.useTrainer (0); // [cite: 204]
    cout << endl; // [cite: 205]
    player2.displayAction(); // [cite: 206]
    return 0; // [cite: 207]
}
```

#### Output: [cite: 209]

```text
Hadi is activating a Pokemon Card: Pikachu [cite: 210]
Hadi is attaching Energy Card of type Electric to the Pokemon Pikachu [cite: 211]
Hadi is attaching Energy Card of type Electric to the Pokemon Pikachu [cite: 211]

Bench cards for Player Hadi: [cite: 213]
Trainer Card Name: Ash, Effect: heal all your action pokemon [cite: 214]

Action cards for Player Hadi: [cite: 215]
Pokemon Card Name: Pikachu, Type: Electric, Evolution Level: 2 of the family "Pikachu, HP: 100" [cite: 216]
Attacks: [cite: 217]
Attack #0: [cite: 218]
Attack cost: 2 [cite: 219]
Attack current energy storage: 2 [cite: 220]
Attack description: thunder bolt [cite: 221]
Attack damage: 20 [cite: 222]
Attack #1: [cite: 223]
Attack cost: 3 [cite: 224]
Attack current energy storage: 2 [cite: 225]
Attack description: thunder storm [cite: 225]
Attack damage: 30 [cite: 226]

Germain is activating a Pokemon Card: Bulbasaur [cite: 227]
Germain is attaching Energy Card of type Grass to the Pokemon Bulbasaur [cite: 228]

Bench cards for Player Germain: [cite: 229]
Trainer Card Name: Brock, Effect: heal all your action pokemon [cite: 230]

Action cards for Player Germain: [cite: 231]
Pokemon Card Name: Bulbasaur, Type: Grass, Evolution Level: 1 of the family "Bulbasaur, HP: 100" [cite: 232, 233]
Attacks: [cite: 234]
Attack #0: [cite: 235]
Attack cost: 2 [cite: 236]
Attack current energy storage: 1 [cite: 237]
Attack description: Leech Seed [cite: 238]
Attack damage: 15 [cite: 239]
Attack #1: [cite: 240]
Attack cost: 3 [cite: 241]
Attack current energy storage: 1 [cite: 242]
Attack description: Vine Whip [cite: 242]
Attack damage: 25 [cite: 243]
Only 2 attacks exist. [cite: 244]

Hadi attacking Germain's Pokemon Bulbasaur with the Pokemon Pikachu with its attack: thunder bolt [cite: 245]
Reducing 20 from Germain's Pokemon's HP [cite: 246]
Pokemon Bulbasaur is still alive [cite: 247]

Action cards for Player Germain: [cite: 248]
Pokemon Card [cite: 249]
Name: Bulbasaur, Type: Grass, Evolution Level: 1 of the family "Bulbasaur, HP: 80" [cite: 250, 251]
Attacks: [cite: 252]
Attack #0: [cite: 253]
Attack cost: 2 [cite: 254]
Attack current energy storage: 1 [cite: 255]
Attack description: Leech Seed [cite: 256]
Attack damage: 15 [cite: 257]
Attack #1: [cite: 258]
Attack cost: 3 [cite: 259]
Attack current energy storage: 1 [cite: 260]
Attack description: Vine Whip [cite: 261]
Attack damage: 25 [cite: 262]

Germain is using the Trainer Card to "heal all your action pokemon" [cite: 263]

Action cards for Player Germain: [cite: 264]
Pokemon Card [cite: 265]
Name: Bulbasaur, Type: Grass, Evolution Level: 1 of the family "Bulbasaur, HP: 100" [cite: 266, 270]
Attacks: [cite: 267]
Attack #0: [cite: 268]
Attack cost: 2 [cite: 269]
Attack current energy storage: 1 [cite: 272]
Attack description: Leech Seed [cite: 273]
Attack damage: 15 [cite: 274]
Attack #1: [cite: 275]
Attack cost: 3 [cite: 276]
Attack current energy storage: 1 [cite: 277]
Attack description: Vine Whip [cite: 277]
Attack damage: 25 [cite: 278]
```