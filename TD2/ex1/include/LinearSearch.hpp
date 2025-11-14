#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include "SearchingAlgorithm.hpp"
#include <vector>

class LinearSearch : public SearchingAlgorithm
{
public:
    virtual ~LinearSearch() override; /* destructeur */

    /* fonction 'search' override */
    virtual int search(std::vector<int>, int) override;
};

#endif /* LinearSearch_hpp */