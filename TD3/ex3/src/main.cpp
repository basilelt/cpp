#include <iostream>
#include <queue> // FIFO
#include <stack> // LIFO
#include <cctype>

using namespace std;

bool isPalindrome(const string &input)
{
    // Prepare a queue and a stack
    std::queue<char> q;
    std::stack<char> s;

    for (char c : input)
    {
        // use lowercase
        c = std::tolower(c);
        // push to both queue and stack
        q.push(c);
        s.push(c);
    }

    // Iterate the queue while not empty, pop on iteration
    for (; !q.empty(); q.pop())
    {
        // If start letter is not end letter then not a palindrome
        if (q.front() != s.top())
            return false;

        // Pop the stack
        s.pop();
    }
    return true;
}

int main()
{
    cout << boolalpha;
    cout << "Is 'racecar' a palindrome? "
         << isPalindrome("racecar") << endl;
    cout << "Is 'hello' a palindrome? "
         << isPalindrome("hello") << endl;

    cout << endl
         << "The complexity of isPalindrome is O(n)" << endl;
    return 0;
}