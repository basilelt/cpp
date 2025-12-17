#include "distances.hpp"
#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>

double euclidean_distance(const std::vector<double> &a, const std::vector<double> &b)
{
    if (a.size() != b.size())
    {
        return std::numeric_limits<double>::infinity();
    }
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i)
    {
        double diff = a[i] - b[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

double dtw_distance(const std::vector<double> &x, const std::vector<double> &y)
{
    int L = x.size();
    if (L != (int)y.size())
    {
        return std::numeric_limits<double>::infinity();
    }
    std::vector<std::vector<double>> D(L + 1, std::vector<double>(L + 1, std::numeric_limits<double>::infinity()));
    D[0][0] = 0.0;
    for (int i = 1; i <= L; ++i)
    {
        for (int j = 1; j <= L; ++j)
        {
            double cost = (x[i - 1] - y[j - 1]) * (x[i - 1] - y[j - 1]);
            D[i][j] = cost + std::min({D[i - 1][j], D[i][j - 1], D[i - 1][j - 1]});
        }
    }
    return sqrt(D[L][L]);
}

double edit_distance_real_sequences(const std::vector<double> &x, const std::vector<double> &y)
{
    // Placeholder implementation: for now, return euclidean distance
    // In a full implementation, EDR uses edit operations with a threshold for matching
    return euclidean_distance(x, y);
}