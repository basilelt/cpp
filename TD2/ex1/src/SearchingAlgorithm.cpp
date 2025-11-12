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

/* Surcharge de l'opérateur d'affichage */
std::ostream &SearchingAlgorithm::PrintOn(std::ostream &os) const
{
    os << "Number of comparisons: ";
    os << numberComparisons;
    return os;
}

int SearchingAlgorithm::search(std::vector<int> v1, int element)
{
    std::vector<int>::iterator it = v1.begin();
    for (; it != v1.end(); ++it)
    {
        if (*it == element)
        {
            return std::distance(v1.begin(), it);
        }
    }
    return -1;
}
