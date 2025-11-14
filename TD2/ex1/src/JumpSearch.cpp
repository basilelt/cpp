#include "JumpSearch.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>

/* Destructeur */
JumpSearch::~JumpSearch()
{
}

int JumpSearch::search(std::vector<int> v1, int target)
{
    /* Recherche jump */
    totalSearch++; /* Incrémente le nombre de recherches pour toutes instances de la classe */
    
    int n = v1.size();
    if (n == 0)
        return -1;

    int step = static_cast<int>(std::sqrt(n));
    int prev = 0;

    // Jump ahead
    while (prev < n && v1[std::min(step, n) - 1] < target)
    {
        numberComparisons++; /* Comparaison pour vérifier si le bloc est passé */
        prev = step;
        step += static_cast<int>(std::sqrt(n));
        if (prev >= n)
            return -1;
    }

    // Linear search in the block
    for (int i = prev; i < std::min(step, n); ++i)
    {
        numberComparisons++; /* Comparaison pour vérifier l'égalité */
        if (v1[i] == target)
        {
            return i;
        }
    }
    return -1;
}