#include "MatrixBase.hpp"
#include <iostream>
#include <iomanip>

/* Constructeur par défaut */
/* Fait une matrice 2x2 avec des valeurs initiales */
template <typename T>
MatrixBase<T>::MatrixBase() : MatrixBase(std::vector<T>(4, initialValue), 2, 2)
{
}

/* Constructeur avec paramètres */
template <typename T>
MatrixBase<T>::MatrixBase(std::vector<T> _data, size_t _rows, size_t _cols) : data(_data), rows(_rows), cols(_cols)
{
}

/* Constructeur de copie */
template <typename T>
MatrixBase<T>::MatrixBase(const MatrixBase &m) : MatrixBase(m.data, m.rows, m.cols)
{
}

/* Destructeur */
template <typename T>
MatrixBase<T>::~MatrixBase()
{
}

/* Getters et Setters */
template <typename T>
T MatrixBase<T>::getElement(unsigned int row, unsigned int col) const
{
    // rows, cols, row et col commencent à 1
    return data[(row - 1) * cols + (col - 1)];
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
    data[(row - 1) * cols + (col - 1)] = element;
}

template <typename T>
std::ostream &MatrixBase<T>::Display(std::ostream &os) const
{
    for (size_t r = 0; r < rows; r++)
    {
        for (size_t c = 0; c < cols; c++)
        {
            os << std::setfill(' ') << std::setw(4) << getElement(r + 1, c + 1);
        }
        os << std::endl;
    }
    return os;
}

/* Surcharge de l'opérateur d'affichage */
template <typename T>
std::ostream &MatrixBase<T>::PrintOn(std::ostream &os) const
{
    return os;
}
