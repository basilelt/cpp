//
//  Path.cpp
//  exam2013
//
//  Created by Jean-Marc Perronne on 19/03/13.
//  Copyright (c) 2013 Jean-Marc Perronne. All rights reserved.
//

#include "Path.h"

Path::~Path()
{
    for(iterator it=path.begin(); it!=path.end(); it++)
        delete *it;
}

void Path::move(int dx, int dy)
{
    for(iterator it=path.begin(); it!=path.end(); it++)
         (*it)->move(dx,dy);
}

void Path::addPoint(int x, int y)
{
    path.push_back(new Point(x,y));
}

unsigned int Path::size() const
{
    return (unsigned int) path.size();
}

std::ostream& Path::printOn(std::ostream& os)const
{
    os << '[';
    for(const_iterator it=path.begin(); it!=path.end(); it++)
    {
        (*it)->printOn(os);
        os << ',';
    }
    os << ']';

    
    return os;
}