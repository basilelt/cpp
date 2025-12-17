#include "Class.hpp"

unsigned int Class::ref = 0; /* existe dans la mémoire */

Class::Class()
{
    ref++;
}

Class::Class(const Class &c)
{
    ref++;
}

Class::~Class()
{
    ref--;
}

unsigned int Class::GetRef()
{
    return ref;
}