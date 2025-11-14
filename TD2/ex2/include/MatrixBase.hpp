#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include "Base.hpp"
#include <vector>

template <typename T>
class MatrixBase : public Base
{
public:
    MatrixBase();                               /* constructeur par défaut */
    MatrixBase(std::vector<T>, size_t, size_t); /* constructeur avec paramètres */
    MatrixBase(const MatrixBase &);             /* constructeur de copie */
    virtual ~MatrixBase() override;             /* destructeur */

    virtual T getElement(unsigned int, unsigned int) const;
    virtual int getRows() const;
    virtual int getCols() const;
    virtual void addElement(T, unsigned int, unsigned int);

    /* Pas d'ancêtre, pas d'override */
    virtual std::ostream &Display(std::ostream &os) const;

    /* Override car ancêtre */
    virtual std::ostream &PrintOn(std::ostream &os) const override;

protected:
    std::vector<T> data;
    T initialValue = T(); /* Valeur initiale des éléments du tableau */

private:
    size_t rows, cols;
};

#include "MatrixBase.tpp"
#endif /* MatrixBase_hpp */