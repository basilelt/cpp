#ifndef BASE_H
#define BASE_H

#include <iostream>
#include "Class.hpp"

/* Abstraite, une méthode virtuelle pure */
class Base : public Class
{
public:
    virtual std::ostream &PrintOn(std::ostream &) const = 0;
    friend std::ostream &operator<<(std::ostream &, const Base &);
};

#endif /* Base_hpp */