#include "LinearSearch.hpp"
#include <iostream>

/* Destructeur */
LinearSearch::~LinearSearch()
{
}

int LinearSearch::search(std::vector<int> v1, int target)
{
    /* Recherche linéaire */
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