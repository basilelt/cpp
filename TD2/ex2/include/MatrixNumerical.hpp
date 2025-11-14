#ifndef MATRIXNUMERICAL_H
#define MATRIXNUMERICAL_H

#include "MatrixBase.hpp"
#include <vector>

class MatrixNumerical : public MatrixBase
{
public:
    virtual ~MatrixNumerical() override;                      /* destructeur */

    virtual T getElement(unsigned int, unsigned int) const;
    virtual int getRows() const;
    virtual int getCols() const;
    virtual void addElement(T, unsigned int, unsigned int);

protected:
    std::vector<T> data;
    T initialValue = T(); /* Valeur initiale des éléments du tableau */

private:
    size_t rows, cols;
};

#endif /* MatrixBase_hpp */