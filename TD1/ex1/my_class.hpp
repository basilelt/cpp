#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <string>

using namespace std;

class My_class
{
public:
    My_class(const std::string &_str);
    virtual ~My_class() = default;

    void print_my_element() const;

private:
    string str;
};

#endif