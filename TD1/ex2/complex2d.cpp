#include "complex2d.hpp"
#include <iostream>
#include <string>

using namespace std;

Complex2D::Complex2D() : re(0), im(0)
{
}

Complex2D::Complex2D(double _re, double _im) : re(_re), im(_im)
{
}

Complex2D::Complex2D(double _re) : re(_re), im(0)
{
}

Complex2D::Complex2D(const Complex2D &complex) : re(complex.re), im(complex.im)
{
}

Complex2D &Complex2D::operator+(const Complex2D &complex)
{
    
}