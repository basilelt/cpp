#ifndef COMPLEX2D_H
#define COMPLEX2D_H

#include <string>

class Complex2D
{
public:
    Complex2D();
    Complex2D(double, double);
    Complex2D(double);
    Complex2D(const Complex2D &);
    virtual ~Complex2D() = default;

    virtual Complex2D &operator+=(const Complex2D &);
    virtual Complex2D operator+(const Complex2D &) const;
    virtual Complex2D &operator-=(const Complex2D &);
    virtual Complex2D operator-(const Complex2D &) const;
    virtual Complex2D &operator*=(const Complex2D &);
    virtual Complex2D operator*(const Complex2D &) const;
    virtual Complex2D &operator/=(const Complex2D &);
    virtual Complex2D operator/(const Complex2D &) const;
    virtual Complex2D &operator=(const Complex2D &);
    virtual bool operator<(const Complex2D &) const;
    virtual bool operator>(const Complex2D &) const;
    virtual bool operator<=(const Complex2D &) const;
    virtual bool operator>=(const Complex2D &) const;
    virtual bool operator==(const Complex2D &) const;
    virtual bool operator!=(const Complex2D &) const;

    virtual double getRe() const;
    virtual double getIm() const;
    virtual void setRe(double);
    virtual void setIm(double);

    virtual std::ostream& printOn(std::ostream&) const;

private:
    double re, im;
};

#endif