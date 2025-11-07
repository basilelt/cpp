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

Complex2D &Complex2D::operator+=(const Complex2D &complex)
{
    re += complex.re;
    im += complex.im;
    return *this;
}

Complex2D Complex2D::operator+(const Complex2D &complex) const
{
    return Complex2D(re + complex.re, im + complex.im);
}

Complex2D &Complex2D::operator-=(const Complex2D &complex)
{
    re -= complex.re;
    im -= complex.im;
    return *this;
}

Complex2D Complex2D::operator-(const Complex2D &complex) const
{
    return Complex2D(re - complex.re, im - complex.im);
}

Complex2D &Complex2D::operator*=(const Complex2D &complex)
{
    double new_re = re * complex.re - im * complex.im;
    double new_im = re * complex.im + im * complex.re;
    re = new_re;
    im = new_im;
    return *this;
}

Complex2D Complex2D::operator*(const Complex2D &complex) const
{
    double new_re = re * complex.re - im * complex.im;
    double new_im = re * complex.im + im * complex.re;
    return Complex2D(new_re, new_im);
}

Complex2D &Complex2D::operator/=(const Complex2D &complex)
{
    double denominator = complex.re * complex.re + complex.im * complex.im;
    double new_re = (re * complex.re + im * complex.im) / denominator;
    double new_im = (im * complex.re - re * complex.im) / denominator;
    re = new_re;
    im = new_im;
    return *this;
}

Complex2D Complex2D::operator/(const Complex2D &complex) const
{
    double denominator = complex.re * complex.re + complex.im * complex.im;
    double new_re = (re * complex.re + im * complex.im) / denominator;
    double new_im = (im * complex.re - re * complex.im) / denominator;
    return Complex2D(new_re, new_im);
}

Complex2D &Complex2D::operator=(const Complex2D &complex)
{
    if (&complex != this)
    {
        re = complex.re;
        im = complex.im;
    }
    return *this;
}

bool Complex2D::operator<(const Complex2D &complex) const
{
    return (re < complex.re) || (re == complex.re && im < complex.im);
}

bool Complex2D::operator>(const Complex2D &complex) const
{
    return (re > complex.re) || (re == complex.re && im > complex.im);
}

bool Complex2D::operator<=(const Complex2D &complex) const
{
    return (re < complex.re) || (re == complex.re && im <= complex.im);
}

bool Complex2D::operator>=(const Complex2D &complex) const
{
    return (re > complex.re) || (re == complex.re && im >= complex.im);
}

bool Complex2D::operator==(const Complex2D &complex) const
{
    return (re == complex.re) && (im == complex.im);
}

bool Complex2D::operator!=(const Complex2D &complex) const
{
    return !(*this == complex);
}

double Complex2D::getRe() const
{
    return re;
}

double Complex2D::getIm() const
{
    return im;
}

void Complex2D::setRe(double _re)
{
    re = _re;
}

void Complex2D::setIm(double _im)
{
    im = _im;
}

ostream &Complex2D::printOn(ostream &os) const
{
    os << re << " + " << im << "i";
    return os;
}
