#include "SearchingAlgorithm.hpp"
#include <iostream>

// Static member definitions
unsigned int SearchingAlgorithm::totalComparisons = 0;
unsigned int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

/* Constructeur par défaut */
SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0)
{
}

/* Destructeur */
SearchingAlgorithm::~SearchingAlgorithm()
{
}

int SearchingAlgorithm::search(std::vector<int> v1, int target)
{
    totalSearch++; /* Incrémente le nombre de recherches pour toutes instances de la classe */
    std::vector<int>::iterator it = v1.begin();
    for (; it != v1.end(); ++it)
    {
        numberComparisons++; /* Incrémente le nombre de comparaisons pour cette instance */
        if (*it == target)
        {
            return std::distance(v1.begin(), it);
        }
    }
    return -1;
}

std::ostream &SearchingAlgorithm::displaySearchResults(std::ostream &os, int results, int target) const
{
    if (results == -1)
    {
        os << "Element " << target << " non trouvé." << std::endl;
    }
    else
    {
        os << "Element " << target << " trouvé à l'indice " << results << ".";
    }

    totalComparisons += numberComparisons; /* Incrémente le nombre total de comparaisons pour toutes instances de la classe */
    averageComparisons = totalComparisons / totalSearch;
    // os << std::endl << "Nombre de comparaisons pour cette recherche: ";
    // os << numberComparisons;
    // os << std::endl << "Nombre total de recherches: ";
    // os << totalSearch;

    os << std::endl
       << "Nombre total de comparaisons: "
       << totalComparisons
       << std::endl
       << "Nombre moyen de comparaisons par recherche: "
       << averageComparisons;
    return os;
}

/* Surcharge de l'opérateur d'affichage */
std::ostream &SearchingAlgorithm::PrintOn(std::ostream &os) const
{
    return os;
}