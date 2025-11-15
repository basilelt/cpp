#include <iostream>
#include "MatrixNumerical.hpp"

template <typename T>
void testMatrixNumerical(const std::string &typeName)
{
    std::cout << "Testing MatrixNumerical<" << typeName << ">" << std::endl;

    // Create a 2x2 matrix
    std::vector<T> data = {T(1), T(2), T(3), T(4)};
    MatrixNumerical<T> mat1(data, 2, 2);
    std::cout << "Matrix 1:" << std::endl;
    mat1.Display(std::cout);

    // Test identity
    MatrixNumerical<T> id = MatrixNumerical<T>::getIdentity(2);
    std::cout << "Identity 2x2:" << std::endl;
    id.Display(std::cout);

    // Test addition
    MatrixNumerical<T> sum = mat1 + id;
    std::cout << "Matrix 1 + Identity:" << std::endl;
    sum.Display(std::cout);

    // Test determinant
    T det = mat1.getDeterminant();
    std::cout << "Determinant of Matrix 1: " << det << std::endl;

    // Test inverse
    try {
        MatrixNumerical<T> inv = mat1.getInverse();
        std::cout << "Inverse of Matrix 1:" << std::endl;
        inv.Display(std::cout);
    } catch (const std::exception &e) {
        std::cout << "Error getting inverse: " << e.what() << std::endl;
    }

    // Test multiplication
    MatrixNumerical<T> prod = mat1 * id;
    std::cout << "Matrix 1 * Identity:" << std::endl;
    prod.Display(std::cout);

    // Test division (Matrix1 / Identity = Matrix1 * Inverse(Identity) = Matrix1)
    try {
        MatrixNumerical<T> div = mat1 / id;
        std::cout << "Matrix 1 / Identity:" << std::endl;
        div.Display(std::cout);
    } catch (const std::exception &e) {
        std::cout << "Error in division: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

int main()
{
    testMatrixNumerical<int>("int");
    testMatrixNumerical<float>("float");
    testMatrixNumerical<double>("double");

    return 0;
}
