#ifndef BASE_H
#define BASE_H

#include <iostream>
#include "Class.hpp"

/* Abstraite, une méthode virtuelle pure */
class Base : public Class
{
public:
    virtual std::ostream &PrintOn(std::ostream &os) const = 0; /* Méthode virtuelle pure */
    friend std::ostream &operator<<(std::ostream &os, const Base &);
};

#endif /* Base_hpp */