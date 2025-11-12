#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include "Base.hpp"
#include <vector>

class SearchingAlgorithm : public Base
{
public:
    SearchingAlgorithm();          /* constructeur par défaut */
    virtual ~SearchingAlgorithm(); /* destructeur */

    /* fonction 'search' virtuelle pure (=0) */
    virtual int search(std::vector<int>, int) = 0;

    /* Override car ancêtre */
    virtual std::ostream &PrintOn(std::ostream &os) const override;

private:
    unsigned int numberComparisons;
    static unsigned int totalComparisons, totalSearch, averageComparisons;
};

#endif /* SearchingAlgorithm_hpp */