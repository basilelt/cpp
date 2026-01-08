//
//  Line.cpp
//  exam2013
//
//  Created by Jean-Marc Perronne on 19/03/13.
//  Copyright (c) 2013 Jean-Marc Perronne. All rights reserved.
//

#include "Line.h"

Line::Line()
{}

Line::Line(const Point& _start, const Point& _end):
start(_start), end(_end)
{}

void Line::move(int dx, int dy)
{
    start.move(dx, dy);
    end.move(dx,dy);
}

Point Line::getStart()const
{
    return start;
}

Point Line::getEnd()const
{
    return end;
}

std::ostream& Line::printOn(std::ostream& os)const
{
    os << "Line("; 
    start.printOn(os);
    os << ',';
    end.printOn(os) << ')';
    return  os;
}
