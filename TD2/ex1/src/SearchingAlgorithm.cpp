#include "SearchingAlgorithm.hpp"
#include <iostream>

/* Constructeur par défaut */
SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0)
{
}

/* Destructeur */
SearchingAlgorithm::~SearchingAlgorithm()
{
}

int SearchingAlgorithm::search(std::vector<int> v1, int element)
{
    totalSearch++; /* Incrémente le nombre de recherches pour toutes instances de la classe */
    std::vector<int>::iterator it = v1.begin();
    for (; it != v1.end(); ++it)
    {
        numberComparisons++; /* Incrémente le nombre de comparaisons pour cette instance */
        if (*it == element)
        {
            return std::distance(v1.begin(), it);
        }
    }
    return -1;
}

std::ostream &SearchingAlgorithm::displaySearchResults(std::ostream &os, int results, int target) const
{

    totalComparisons += numberComparisons; /* Incrémente le nombre total de comparaisons pour toutes instances de la classe */
    averageComparisons = totalComparisons / totalSearch;
    os << std::endl << "Nombre total de comparaisons: ";
    os << totalComparisons;
    return os;
}