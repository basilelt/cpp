#include "my_class.hpp"
#include <iostream>
#include <string>

using namespace std;

My_class::My_class(const string &_str) : str(_str)
{
}

void My_class::print_my_element() const
{
    cout << str << endl;
}
