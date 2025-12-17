#include <iostream>
#include "Base.hpp"

/* N'appartient pas à la classe */
std::ostream &operator<<(std::ostream &os, const Base &o)
{
    return o.PrintOn(os);
}