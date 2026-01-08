//
//  Path.h
//  exam2013
//
//  Created by Jean-Marc Perronne on 19/03/13.
//  Copyright (c) 2013 Jean-Marc Perronne. All rights reserved.
//

#ifndef __exam2013__Path__
#define __exam2013__Path__

#include <iostream>
#include<vector>
#include "Geometric.h"
#include "Point.h"

class Path: public Geometric
{
public:
    virtual ~Path();

    virtual void move(int, int);
    virtual void addPoint(int, int);
    virtual unsigned int size() const;
    
    virtual std::ostream& printOn(std::ostream&)const;
    
private:
    typedef std::vector<Point*>::iterator iterator;
    typedef std::vector<Point*>::const_iterator const_iterator;
  
    std::vector<Point*> path;
};
#endif /* defined(__exam2013__Path__) */
