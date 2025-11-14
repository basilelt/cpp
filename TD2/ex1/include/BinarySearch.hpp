#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "SearchingAlgorithm.hpp"
#include <vector>

class BinarySearch : public SearchingAlgorithm
{
public:
    virtual ~BinarySearch() override; /* destructeur */

    /* fonction 'search' override */
    virtual int search(std::vector<int>, int) override;
};

#endif /* BinarySearch_hpp */