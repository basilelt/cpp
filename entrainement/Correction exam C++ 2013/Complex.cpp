//
//  Complex.cpp
//  exam2013
//
//  Created by Jean-Marc Perronne on 19/03/13.
//  Copyright (c) 2013 Jean-Marc Perronne. All rights reserved.
//

#include "Complex.h"
#include <cmath>

Complex::Complex(double _re, double _im):
re(_re),im(_im)
{
}

double Complex::module()const
{
    return sqrt(re*re+im*im);
}

std::ostream& Complex::printOn(std::ostream & os)const
{
    os << re << "+i" << im;
    return os;
}

Complex Complex::operator+(const Complex & c)const
{
    return Complex(re+c.re, im+c.im);
}