#include "KNN.hpp"

/* Constructeur par défaut */
template <typename T>
KNN<T>::KNN() : k(1)
{
}

/* Constructeur avec paramètres */
template <typename T>
KNN<T>::KNN(int _k) : k(_k)
{
}

/* Getters et Setters */
template <typename T>
int KNN<T>::getK() const
{
    return k;
}

