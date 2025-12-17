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

template <typename T>
std::vector<int> KNN<T>::findNearestNeighbors(
    std::vector<T> &trainData,
    T &target)
{
    std::vector<std::pair<double, int>> distances;

    for (size_t i = 0; i < trainData.size(); ++i)
    {
        double distance = similarityMeasure(trainData[i], target);
        distances.emplace_back(distance, i);
    }

    std::sort(distances.begin(), distances.end());

    std::vector<int> neighbors;
    for (int i = 0; i < k && i < static_cast<int>(distances.size()); ++i)
    {
        neighbors.push_back(distances[i].second);
    }

    return neighbors;
}

