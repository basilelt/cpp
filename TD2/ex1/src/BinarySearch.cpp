#include "BinarySearch.hpp"
#include <iostream>
#include <algorithm>

/* Destructeur */
BinarySearch::~BinarySearch()
{
}

int BinarySearch::search(std::vector<int> v1, int target)
{
    /* Recherche binaire */
    totalSearch++; /* Incrémente le nombre de recherches pour toutes instances de la classe */

    std::sort(v1.begin(), v1.end()); /* Trie le vecteur pour la recherche binaire */

    int left = 0;
    int right = v1.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        numberComparisons++; /* Comparaison pour vérifier l'égalité ou l'ordre */

        if (v1[mid] == target)
        {
            return mid;
        }
        else if (v1[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}