#ifndef JUMPSEARCH_H
#define JUMPSEARCH_H

#include "SearchingAlgorithm.hpp"
#include <vector>

class JumpSearch : public SearchingAlgorithm
{
public:
    virtual ~JumpSearch() override; /* destructeur */

    /* fonction 'search' override */
    virtual int search(std::vector<int>, int) override;
};

#endif /* JumpSearch_hpp */