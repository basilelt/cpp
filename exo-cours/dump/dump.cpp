#include "dump.hpp"
#include <iostream>
using namespace std;

void dump(int *tab, unsigned int n)
{
    for (int i = 0; i < n; i++)
        cout << endl
             << tab[i];
};
