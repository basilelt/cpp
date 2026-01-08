//
//  Point.cpp
//  exam2013
//
//  Created by Jean-Marc Perronne on 19/03/13.
//  Copyright (c) 2013 Jean-Marc Perronne. All rights reserved.
//

#include "Point.h"

Point::Point():
x(0),y(0)
{}

Point::Point(int _x, int _y):
x(_x),y(_y)
{}

void Point::move(int dx,int dy)
{
    x+=dx;
    y+=dy;
}

std::ostream& Point::printOn(std::ostream& os)const
{
    return os << "Point(" << x << ',' << y << ')';
}