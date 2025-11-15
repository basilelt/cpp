#include <stdexcept>

// Fonction auxiliaire pour le cofacteur
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getCoFactor(const MatrixNumerical<T> &mat, int p, int q)
{
    int n = mat.getRows();
    MatrixNumerical<T> cofactor(std::vector<T>((n - 1) * (n - 1), T()), n - 1, n - 1);

    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                cofactor.addElement(mat.getElement(row + 1, col + 1), i + 1, j + 1);
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
    int n = this->getRows();
    if (n == 1)
    {
        return this->getElement(1, 1);
    }
    if (n == 2)
    {
        return this->getElement(1, 1) * this->getElement(2, 2) - this->getElement(1, 2) * this->getElement(2, 1);
    }

    T det = T();
    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        MatrixNumerical<T> cofactor = getCoFactor(*this, 0, i);
        det += sign * this->getElement(1, i + 1) * cofactor.getDeterminant();
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
    int n = this->getRows();
    T det = this->getDeterminant();
    if (det == T())
    {
        throw std::invalid_argument("Matrix is singular");
    }

    MatrixNumerical<T> adj(std::vector<T>(n * n, T()), n, n);
    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            MatrixNumerical<T> cofactor = getCoFactor(*this, i, j);
            T cofactorDet = cofactor.getDeterminant();
            adj.addElement(sign * cofactorDet, j + 1, i + 1); // Transpose
            sign = -sign;
        }
        if (n % 2 == 0)
            sign = -sign; // Adjust sign for next row
    }

    MatrixNumerical<T> inv(std::vector<T>(n * n, T()), n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inv.addElement(adj.getElement(i + 1, j + 1) / det, i + 1, j + 1);
        }
    }
    return inv;
}

// Matrice identité statique
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int size)
{
    std::vector<T> data(size * size, T());
    for (int i = 0; i < size; i++)
    {
        data[i * size + i] = T(1);
    }
    return MatrixNumerical<T>(data, size, size);
}

// Opérateurs
template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T> &other) const
{
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols())
    {
        throw std::invalid_argument("Matrices must have the same dimensions");
    }
    int rows = this->getRows();
    int cols = this->getCols();
    std::vector<T> result(rows * cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i * cols + j] = this->getElement(i + 1, j + 1) + other.getElement(i + 1, j + 1);
        }
    }
    return MatrixNumerical<T>(result, rows, cols);
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T> &other) const
{
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols())
    {
        throw std::invalid_argument("Matrices must have the same dimensions");
    }
    int rows = this->getRows();
    int cols = this->getCols();
    std::vector<T> result(rows * cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i * cols + j] = this->getElement(i + 1, j + 1) - other.getElement(i + 1, j + 1);
        }
    }
    return MatrixNumerical<T>(result, rows, cols);
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T> &other) const
{
    if (this->getCols() != other.getRows())
    {
        throw std::invalid_argument("Number of columns of first matrix must equal number of rows of second matrix");
    }
    int rows = this->getRows();
    int cols = other.getCols();
    int common = this->getCols();
    std::vector<T> result(rows * cols, T());
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            T sum = T();
            for (int k = 0; k < common; k++)
            {
                sum += this->getElement(i + 1, k + 1) * other.getElement(k + 1, j + 1);
            }
            result[i * cols + j] = sum;
        }
    }
    return MatrixNumerical<T>(result, rows, cols);
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const MatrixNumerical<T> &other) const
{
    MatrixNumerical<T> inv = other.getInverse();
    return *this * inv;
}