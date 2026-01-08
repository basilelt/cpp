//
//  Point.h
//  exam2013
//
//  Created by Jean-Marc Perronne on 19/03/13.
//  Copyright (c) 2013 Jean-Marc Perronne. All rights reserved.
//

#ifndef __exam2013__Point__
#define __exam2013__Point__

#include <iostream>
#include "Geometric.h"

class Point: public Geometric
{
public:
    Point();
    Point(int,int);
    ~Point(){};
    
    virtual void move(int,int);
  
    virtual std::ostream& printOn(std::ostream&)const;

private:
    int x,y;
};
#endif /* defined(__exam2013__Point__) */
