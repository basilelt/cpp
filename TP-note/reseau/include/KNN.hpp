#ifndef KNN_H
#define KNN_H

#include "Base.hpp"
#include <vector>

template <typename T>
class KNN : public Base
{
public:
    KNN();    /* constructeur par défaut */
    KNN(int); /* constructeur avec paramètres */
    int getK() const;

    std::vector<int> findNearestNeighbors(
        std::vector<T> &trainData,
        T &target);

    /* méthode virtuelle pure */
    virtual double similarityMeasure(
        T &a,
        T &b) = 0;

protected:
    int k;
};

#include "KNN.tpp"
#endif /* KNN_H */