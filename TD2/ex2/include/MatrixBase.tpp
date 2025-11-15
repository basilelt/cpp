#include "MatrixBase.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>

/* Constructeur par défaut */
/* Fait une matrice 2x2 avec des valeurs initiales */
template <typename T>
MatrixBase<T>::MatrixBase() : data(2, std::vector<T>(2, initialValue)), rows(2), cols(2)
{
}

/* Constructeur avec paramètres */
template <typename T>
MatrixBase<T>::MatrixBase(std::vector<std::vector<T>> _data) : data(_data), rows(_data.size()), cols(_data.empty() ? 0 : _data[0].size())
{
}

/* Constructeur avec paramètres 1D */
template <typename T>
MatrixBase<T>::MatrixBase(std::vector<T> _data, size_t _rows, size_t _cols) : rows(_rows), cols(_cols)
{
    if (_data.size() != _rows * _cols)
    {
        throw std::invalid_argument("Vector size does not match matrix dimensions");
    }
    data.resize(_rows, std::vector<T>(_cols));
    for (size_t i = 0; i < _rows; ++i)
    {
        for (size_t j = 0; j < _cols; ++j)
        {
            data[i][j] = _data[i * _cols + j];
        }
    }
}

/* Constructeur de copie */
template <typename T>
MatrixBase<T>::MatrixBase(const MatrixBase &m) : MatrixBase(m.data)
{
}

/* Destructeur */
template <typename T>
MatrixBase<T>::~MatrixBase()
{
}

/* Getters et Setters */
template <typename T>
T MatrixBase<T>::getElement(size_t row, size_t col) const
{
    return data[row][col];
}

template <typename T>
size_t MatrixBase<T>::getRows() const
{
    return rows;
}

template <typename T>
size_t MatrixBase<T>::getCols() const
{
    return cols;
}

template <typename T>
void MatrixBase<T>::addElement(T element, size_t row, size_t col)
{
    data[row][col] = element;
}

template <typename T>
std::ostream &MatrixBase<T>::Display(std::ostream &os) const
{
    for (size_t r = 0; r < rows; r++)
    {
        for (size_t c = 0; c < cols; c++)
        {
            os << std::setfill(' ') << std::setw(4) << data[r][c];
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
