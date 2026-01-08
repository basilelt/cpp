//
//  Value.h
//  exam2013
//
//  Created by Jean-Marc Perronne on 19/03/13.
//  Copyright (c) 2013 Jean-Marc Perronne. All rights reserved.
//

#ifndef exam2013_Value_h
#define exam2013_Value_h

template<class T>
class Value
{
public:
    Value(const T&);
    virtual ~Value(){};
    
    virtual void setValue(const T& v);
    virtual T getValue()const;
    
    Value<T> operator / (const Value<T>&)const;
    
    virtual std::ostream& printOn(std::ostream&)const;
    
private:
    T value;
};

template<class T>
Value<T>::Value(const T& v):
value(v)
{}

template<class T>
void Value<T>::setValue(const T& v)
{
    value=v;
}

template<class T>
T Value<T>::getValue()const
{
    return value;
}

template<class T>
Value<T> Value<T>::operator / (const Value<T>& r)const
{
    if (r.value == 0) throw "division by zero";
    return Value<T>(value/r.value);
}

template<class T>
std::ostream& Value<T>::printOn(std::ostream& os)const
{
    return os << "Value(" << value << ")";
}


#endif
