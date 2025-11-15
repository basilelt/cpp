#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.hpp"

template <typename T>
class MatrixNumerical : public MatrixBase<T>
{
public:
    MatrixNumerical();                               /* constructeur par défaut */
    MatrixNumerical(std::vector<T>, size_t, size_t); /* constructeur avec paramètres */
    MatrixNumerical(const MatrixNumerical &);        /* constructeur de copie */
    virtual ~MatrixNumerical() override;             /* destructeur */

    // Operators
    MatrixNumerical operator+(const MatrixNumerical &) const;
    MatrixNumerical operator-(const MatrixNumerical &) const;
    MatrixNumerical operator*(const MatrixNumerical &) const;
    MatrixNumerical operator/(const MatrixNumerical &) const;

    // Functions
    T getDeterminant() const;
    MatrixNumerical getInverse() const;
    static MatrixNumerical getIdentity(int size);

private:
    static MatrixNumerical getCoFactor(const MatrixNumerical &mat, int p, int q);
};

#endif /* MatrixNumerical_hpp */

#include "MatrixNumerical.tpp"