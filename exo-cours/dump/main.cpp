#include "dump.hpp"
#include <iostream>
using namespace std;

int main()
{
    cout << "---buff---";
    int buff[] = {12, 25, 8, 6, 586};
    dump(buff, 5);

    cout << endl
         << "---buff2---";
    int *buff2 = new int[2];
    buff2[0] = 45;
    buff2[1] = 100;
    dump(buff2, 2);
    delete buff2;

    return 0;
};
