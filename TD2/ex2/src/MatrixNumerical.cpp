#include "MatrixNumerical.hpp"
#include <iostream>

/* Destructeur */
template <typename T>
MatrixNumerical<T>::~MatrixNumerical()
{
}

/* Getters et Setters */
template <typename T>
T MatrixBase<T>::getElement(unsigned int row, unsigned int col) const
{
    // rows, cols, row et col commencent à 1
    // On est a row * (cols - 1) + col dans le vecteur
    // -1 car l'indexation commence à 0
    return data[(row * (cols - 1) + col) - 1];
}

template <typename T>
int MatrixBase<T>::getRows() const
{
    return rows;
}

template <typename T>
int MatrixBase<T>::getCols() const
{
    return cols;
}

template <typename T>
void MatrixBase<T>::addElement(T element, unsigned int row, unsigned int col)
{
    data[(row * (cols - 1) + col) - 1] = element;
}
