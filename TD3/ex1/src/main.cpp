#include <iostream>
#include <vector>
#include <map>

using namespace std;

void countFrequencyBruteForce(const vector<int> &numbers)
{
    // Votre code
}

map<int, int> countFrequencyOptimal(const vector<int> &numbers)
{
    // Votre code
}

int main()
{
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    // Test countFrequencyBruteForce
    cout << "Frequency-(Brute-Force):" << endl;
    countFrequencyBruteForce(numbers);

    // Test countFrequencyOptimal
    cout << "\nFrequency - (Optimal):" << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto &entry : frequencyMapOptimal)
    {
        cout << entry.first << ": " << entry.second << "- times" << endl;
    }

    return 0;
}