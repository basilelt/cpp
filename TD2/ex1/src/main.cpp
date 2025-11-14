#include <iostream>
#include "LinearSearch.hpp"
#include "JumpSearch.hpp"
#include "BinarySearch.hpp"

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 6;

    // Linear Search
    std::cout << "Linear Search Results:";
    LinearSearch linear;
    int result_linear = linear.search(v1, target);
    linear.displaySearchResults(std::cout, result_linear, target);

    // Jump Search
    std::cout << std::endl << "Jump Search Results:";
    JumpSearch jump;
    int result_jump = jump.search(v1, target);
    jump.displaySearchResults(std::cout, result_jump, target);

    // Binary Search
    std::cout << std::endl << "Binary Search Results:";
    BinarySearch binary;
    int result_binary = binary.search(v1, target);
    binary.displaySearchResults(std::cout, result_binary, target);

    return 0;
}
