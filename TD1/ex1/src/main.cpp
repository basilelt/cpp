#include "printstring.hpp"
#include "my_class.hpp"
#include <iostream>

using namespace std;

int main()
{
    cout << "Choose 1 for printstring, 2 for my_class: ";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        print_string("Hello World !");
    }
    else if (choice == 2)
    {
        My_class object("Hello World !");
        object.print_my_element();
    }
    else
    {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
