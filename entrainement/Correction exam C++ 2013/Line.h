//
//  Line.h
//  exam2013
//
//  Created by Jean-Marc Perronne on 19/03/13.
//  Copyright (c) 2013 Jean-Marc Perronne. All rights reserved.
//


#ifndef __exam2013__Line__
#define __exam2013__Line__

#include <iostream>
#include "Geometric.h"
#include "Point.h"

class Line :public Geometric
{
public:
    Line();
    Line(const Point&, const Point&);
    virtual ~Line(){};
    
    virtual void move(int, int);
    
    virtual Point getStart()const;
    virtual Point getEnd()const;

    virtual std::ostream& printOn(std::ostream&)const;
    
private:
    Point end, start;
};
#endif /* defined(__exam2013__Line__) */
