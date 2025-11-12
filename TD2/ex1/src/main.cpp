#include <iostream>
#include "LinearSearch.hpp"

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    LinearSearch linear;
    int target = 3;
    int result = linear.search(v1, target);

    linear.displaySearchResults(std::cout, result, target);
    return 0;
}
