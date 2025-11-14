#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include "Base.hpp"
#include <vector>

class SearchingAlgorithm : public Base
{
public:
    SearchingAlgorithm();                   /* constructeur par défaut */
    virtual ~SearchingAlgorithm() override; /* destructeur */

    /* fonction 'search' virtuelle pure (=0) */
    virtual int search(std::vector<int>, int) = 0;
    // virtual int search(std::vector<int>, int); for testing

    virtual std::ostream &displaySearchResults(std::ostream &, int, int) const;

    /* Override car ancêtre */
    virtual std::ostream &PrintOn(std::ostream &os) const override;

    static unsigned int totalComparisons, totalSearch;
    static double averageComparisons;

protected:
    unsigned int numberComparisons;
};

#endif /* SearchingAlgorithm_hpp */