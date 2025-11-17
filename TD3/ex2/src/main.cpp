#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSumBruteForce(const vector<int> &nums, int target)
{
    // Non c++ 11 style loop because of iterator usage
    vector<int>::const_iterator i = nums.begin();
    for (; i != nums.end(); ++i)
    {
        // Starts after i
        vector<int>::const_iterator j = nums.begin();
        for (j = i + 1; j != nums.end(); ++j)
        {
            // If the sum equals the target
            if ((*i + *j) == target)
            {
                // Return the indices of the two numbers
                return {static_cast<int>(distance(nums.begin(), i)),
                        static_cast<int>(distance(nums.begin(), j))};
            }
        }
    }
    // If no solution found
    return {-1, -1};
}

vector<int> twoSumOptimal(const vector<int> &nums, int target)
{
    unordered_map<int, int> numMap; // Map to store number and its index
    for (int i = 0; i < nums.size(); ++i)
    {
        // Complement is the number we need to find to reach the target
        int complement = target - nums[i];

        // Check if the complement exists in the map
        if (numMap.find(complement) != numMap.end())
        {
            return {numMap[complement], i};
        }

        // Store the number with its index
        numMap[nums[i]] = i;
    }
    // If no solution found
    return {-1, -1};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "Brute Force Solution: ["
         << indicesBruteForce[0]
         << ", "
         << indicesBruteForce[1]
         << "]"
         << endl;

    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << "Optimal Solution: ["
         << indicesOptimal[0]
         << ", "
         << indicesOptimal[1]
         << "]"
         << endl;

    cout << endl
         << "We have an O(n^2) complexity in the brute force method and O(n) in the optimal" << endl;

    return 0;
}