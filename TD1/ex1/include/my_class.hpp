#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <string>

class My_class
{
public:
    My_class(const std::string &_str);
    virtual ~My_class() = default;

    void print_my_element() const;

private:
    std::string str;
};

#endif