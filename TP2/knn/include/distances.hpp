#ifndef DISTANCES_H
#define DISTANCES_H

#include <vector>

double euclidean_distance(const std::vector<double> &, const std::vector<double> &);
double dtw_distance(const std::vector<double> &, const std::vector<double> &);
double edit_distance_real_sequences(const std::vector<double> &, const std::vector<double> &);

#endif /* distances_hpp */