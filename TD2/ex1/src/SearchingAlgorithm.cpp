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
