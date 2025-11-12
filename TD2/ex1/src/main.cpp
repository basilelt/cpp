#include <iostream>
#include "LinearSearch.hpp"

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    LinearSearch algo;
    int target = 3;
    int result = algo.search(v1, target);

    algo.displaySearchResults(std::cout, result, target);
    return 0;
}
