#include <stdexcept>

// Fonction auxiliaire pour le cofacteur (free function)
template <typename T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T> &mat, size_t p, size_t q)
{
    size_t n = mat.getRows();
    std::vector<std::vector<T>> cofactorData(n - 1, std::vector<T>(n - 1, T()));
    MatrixNumerical<T> cofactor(cofactorData);

    size_t i = 0, j = 0;
    for (size_t row = 0; row < n; row++)
    {
        for (size_t col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                cofactor.addElement(mat.getElement(row, col), i, j);
                j++;
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return cofactor;
}

// Constructors
template <typename T>
MatrixNumerical<T>::MatrixNumerical() : MatrixBase<T>()
{
}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(std::vector<std::vector<T>> _data) : MatrixBase<T>(_data)
{
}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(std::vector<T> _data, size_t _rows, size_t _cols) : MatrixBase<T>(_data, _rows, _cols)
{
}

template <typename T>
MatrixNumerical<T>::MatrixNumerical(const MatrixNumerical &m) : MatrixBase<T>(m)
{
}

/* Destructeur */
template <typename T>
MatrixNumerical<T>::~MatrixNumerical()
{
}

// Déterminant utilisant l'expansion en cofacteurs
template <typename T>
T MatrixNumerical<T>::getDeterminant() const
{
    if (this->getRows() != this->getCols())
    {
        throw std::invalid_argument("Matrix must be square");
    }
    size_t n = this->getRows();
    if (n == 1)
    {
        return this->getElement(0, 0);
    }
    if (n == 2)
    {
        return this->getElement(0, 0) * this->getElement(1, 1) - this->getElement(0, 1) * this->getElement(1, 0);
    }

    T det = T();
    int sign = 1;
    for (size_t i = 0; i < n; i++)
    {
        MatrixNumerical<T> cofactor = getCoFactor(*this, 0, i);
        det += sign * this->getElement(0, i) * cofactor.getDeterminant();
        sign = -sign;
    }
    return det;
}

// Inverse utilisant la méthode des cofacteurs
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const
{
    if (this->getRows() != this->getCols())
    {
        throw std::invalid_argument("Matrix must be square");
    }
    size_t n = this->getRows();
    T det = this->getDeterminant();
    if (det == T())
    {
        throw std::invalid_argument("Matrix is singular");
    }

    std::vector<std::vector<T>> adjData(n, std::vector<T>(n, T()));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            MatrixNumerical<T> cofactor = getCoFactor(*this, i, j);
            T cofactorDet = cofactor.getDeterminant();
            int sign = ((i + j) % 2 == 0) ? 1 : -1;
            adjData[j][i] = sign * cofactorDet; // Transpose
        }
    }

    MatrixNumerical<T> inv(adjData);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            inv.addElement(adjData[i][j] / det, i, j);
        }
    }
    return inv;
}

// Matrice identité statique
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(size_t size)
{
    std::vector<std::vector<T>> data(size, std::vector<T>(size, T()));
    for (size_t i = 0; i < size; i++)
    {
        data[i][i] = T(1);
    }
    return MatrixNumerical<T>(data);
}

// Opérateurs
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T> &other) const
{
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols())
    {
        throw std::invalid_argument("Matrices must have the same dimensions");
    }
    size_t rows = this->getRows();
    size_t cols = this->getCols();
    std::vector<std::vector<T>> result(rows, std::vector<T>(cols, T()));
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            result[i][j] = this->getElement(i, j) + other.getElement(i, j);
        }
    }
    return MatrixNumerical<T>(result);
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T> &other) const
{
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols())
    {
        throw std::invalid_argument("Matrices must have the same dimensions");
    }
    size_t rows = this->getRows();
    size_t cols = this->getCols();
    std::vector<std::vector<T>> result(rows, std::vector<T>(cols, T()));
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            result[i][j] = this->getElement(i, j) - other.getElement(i, j);
        }
    }
    return MatrixNumerical<T>(result);
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T> &other) const
{
    if (this->getCols() != other.getRows())
    {
        throw std::invalid_argument("Number of columns of first matrix must equal number of rows of second matrix");
    }
    size_t rows = this->getRows();
    size_t cols = other.getCols();
    size_t common = this->getCols();
    std::vector<std::vector<T>> result(rows, std::vector<T>(cols, T()));
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            T sum = T();
            for (size_t k = 0; k < common; k++)
            {
                sum += this->getElement(i, k) * other.getElement(k, j);
            }
            result[i][j] = sum;
        }
    }
    return MatrixNumerical<T>(result);
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const MatrixNumerical<T> &other) const
{
    MatrixNumerical<T> inv = other.getInverse();
    return *this * inv;
}