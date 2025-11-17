#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void countFrequencyBruteForce(const vector<int> &numbers)
{
    // Vector to keep track of which elements got counted
    vector<int> counted;

    // Brute force approach iterating through each element
    vector<int>::const_iterator i = numbers.begin();
    for (; i != numbers.end(); ++i)
    {
        // If i* not found in counted vector
        if (find(counted.begin(), counted.end(), *i) == counted.end())
        {
            int count = 0;
            vector<int>::const_iterator j = numbers.begin();
            for (; j != numbers.end(); ++j)
            {
                if (*i == *j)
                {
                    ++count;
                }
            }
            cout << *i << ": " << count << " times" << endl;
            counted.push_back(*i);
        }
    }
}

map<int, int> countFrequencyOptimal(const vector<int> &numbers)
{
    map<int, int> frequencyMap;
    for (const int &num : numbers)
    {
        // Increment the count for num (the current number) in the map
        frequencyMap[num]++;
    }
    return frequencyMap;
}

int main()
{
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    // Test countFrequencyBruteForce
    cout << "Frequency (Brute Force):" << endl;
    countFrequencyBruteForce(numbers);

    // Test countFrequencyOptimal
    cout << "\nFrequency (Optimal):" << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto &entry : frequencyMapOptimal)
    {
        cout << entry.first << ": " << entry.second << " times" << endl;
    }

    cout << endl
         << "We have an O(n^2) complexity in the brute force method and O(n) in the optimal" << endl;

    return 0;
}