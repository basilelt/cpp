#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.hpp"

template <typename T>
class MatrixNumerical : public MatrixBase<T>
{
public:
    MatrixNumerical();                                         /* constructeur par défaut */
    MatrixNumerical(std::vector<std::vector<T>>);              /* constructeur avec paramètres */
    MatrixNumerical(std::vector<T>, size_t, size_t);           /* constructeur avec paramètres 1D */
    MatrixNumerical(const MatrixNumerical &);                  /* constructeur de copie */
    virtual ~MatrixNumerical() override;                        /* destructeur */

    // Operators
    MatrixNumerical operator+(const MatrixNumerical &) const;
    MatrixNumerical operator-(const MatrixNumerical &) const;
    MatrixNumerical operator*(const MatrixNumerical &) const;
    MatrixNumerical operator/(const MatrixNumerical &) const;

    // Functions
    T getDeterminant() const;
    MatrixNumerical getInverse() const;
    static MatrixNumerical getIdentity(size_t size);
};

#endif /* MatrixNumerical_hpp */

#include "MatrixNumerical.tpp"