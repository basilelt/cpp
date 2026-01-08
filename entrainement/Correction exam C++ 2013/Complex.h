//
//  Complex.h
//  exam2013
//
//  Created by Jean-Marc Perronne on 19/03/13.
//  Copyright (c) 2013 Jean-Marc Perronne. 
//All rights reserved.

//



#ifndef __exam2013__Complex__
#define __exam2013__Complex__


#include <iostream>

class Complex
{

public:
    Complex(double, double=0);

    virtual ~Complex(){};

    
    virtual double module()const;

    virtual std::ostream& printOn(std::ostream&)const;
 
   
    Complex operator + (const Complex&)const;

    
private:
    double re, im;
};


#endif /* defined(__exam2013__Complex__) */
