#ifndef COMPLEX2D_H
#define COMPLEX2D_H

#include <string>

using namespace std;

class Complex2D
{
public:
    Complex2D();
    Complex2D(double, double);
    Complex2D(double);
    Complex2D(const Complex2D &);
    virtual ~Complex2D() = default;

    virtual Complex2D &operator+(const Complex2D &);
    virtual Complex2D &operator-(const Complex2D &);
    virtual Complex2D &operator*(const Complex2D &);
    virtual Complex2D &operator/(const Complex2D &);
    virtual Complex2D &operator<(const Complex2D &);
    virtual Complex2D &operator>(const Complex2D &);

    virtual double getRe() const;
    virtual double getIm() const;
    virtual void setRe();
    virtual void setIm();

private:
    double re, im;
};

#endif