#include "KNN.hpp"
#include "distances.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

KNN::KNN() : KNN(1, "euclidean_distance")
{
}

KNN::KNN(int _k, const std::string &_similarity_measure) : k(_k), similarity_measure(_similarity_measure)
{
}

KNN::KNN(const KNN &knn) : KNN(knn.k, knn.similarity_measure)
{
}

KNN::~KNN()
{
}

KNN &KNN::operator=(const KNN &knn)
{
    if (&knn != this)
    {
        k = knn.k;
        similarity_measure = knn.similarity_measure;
    }
    return *this;
}

int KNN::getK() const
{
    return k;
}

void KNN::setK(int _k)
{
    k = _k;
}

std::string KNN::getSimilarityMeasure() const
{
    return similarity_measure;
}

void KNN::setSimilarityMeasure(const std::string &_similarity_measure)
{
    similarity_measure = _similarity_measure;
}

double KNN::evaluate(const TimeSeriesDataset &trainData, const TimeSeriesDataset &testData, const std::vector<int> &ground_truth)
{
    const auto &train_series = trainData.getData();
    const auto &train_labels = trainData.getLabels();
    const auto &test_series = testData.getData();

    int correct = 0;
    int total = test_series.size();

    for (size_t i = 0; i < test_series.size(); ++i)
    {
        std::vector<std::pair<double, int>> distances;
        for (size_t j = 0; j < train_series.size(); ++j)
        {
            double dist;
            if (similarity_measure == "dtw")
            {
                dist = dtw_distance(test_series[i], train_series[j]);
            }
            else
            {
                dist = euclidean_distance(test_series[i], train_series[j]);
            }
            distances.emplace_back(dist, train_labels[j]);
        }

        // Sort by distance
        std::sort(distances.begin(), distances.end());

        // Get k nearest
        std::map<int, int> vote_count;
        for (int m = 0; m < k && m < (int)distances.size(); ++m)
        {
            vote_count[distances[m].second]++;
        }

        // Find majority
        int predicted = -1;
        int max_votes = 0;
        for (const auto &p : vote_count)
        {
            if (p.second > max_votes)
            {
                max_votes = p.second;
                predicted = p.first;
            }
        }

        if (predicted == ground_truth[i])
        {
            correct++;
        }
    }

    return (double)correct / total;
}

std::ostream &KNN::PrintOn(std::ostream &os) const
{
    os << "KNN with k: " << k << ", similarity_measure: " << similarity_measure;
    return os;
}