#include "complex2d.hpp"
#include <iostream>

int main()
{
    using namespace std;

    // Test default constructor
    Complex2D c1; // 0 + 0i
    cout << "c1 (default): ";
    c1.printOn(cout) << endl;

    // Test constructor with one argument
    Complex2D c2(5); // 5 + 0i
    cout << "c2 (5): ";
    c2.printOn(cout) << endl;

    // Test constructor with two arguments
    Complex2D c3(3, 4); // 3 + 4i
    cout << "c3 (3, 4): ";
    c3.printOn(cout) << endl;

    // Test copy constructor
    Complex2D c4(c3); // Copy of c3
    cout << "c4 (copy of c3): ";
    c4.printOn(cout) << endl;

    // Test assignment operator
    Complex2D c5;
    c5 = c3;
    cout << "c5 (assigned c3): ";
    c5.printOn(cout) << endl;

    // Test addition
    Complex2D sum = c2 + c3; // 5+0i + 3+4i = 8+4i
    cout << "c2 + c3: ";
    sum.printOn(cout) << endl;

    // Test +=
    c1 += c3; // 0+0i += 3+4i = 3+4i
    cout << "c1 after += c3: ";
    c1.printOn(cout) << endl;

    // Test subtraction
    Complex2D diff = c3 - c2; // 3+4i - 5+0i = -2+4i
    cout << "c3 - c2: ";
    diff.printOn(cout) << endl;

    // Test -=
    Complex2D c6(10, 5);
    c6 -= c2; // 10+5i - 5+0i = 5+5i
    cout << "c6 (10,5) after -= c2 (5): ";
    c6.printOn(cout) << endl;

    // Test multiplication
    Complex2D prod = c2 * c3; // 5+0i * 3+4i = 15 + 20i
    cout << "c2 * c3: ";
    prod.printOn(cout) << endl;

    // Test *=
    Complex2D c7(2, 1);
    c7 *= c3; // (2+1i) * (3+4i) = 6+8i + 3i -4 = 2 + 11i
    cout << "c7 (2,1) after *= c3 (3,4): ";
    c7.printOn(cout) << endl;

    // Test division
    Complex2D quot = c3 / c2; // (3+4i)/(5+0i) = 3/5 + 4/5 i
    cout << "c3 / c2: ";
    quot.printOn(cout) << endl;

    // Test /=
    Complex2D c8(10, 5);
    c8 /= c2; // (10+5i)/(5+0i) = 2 + 1i
    cout << "c8 (10,5) after /= c2 (5): ";
    c8.printOn(cout) << endl;

    // Test comparisons
    cout << "c2 < c3: " << (c2 < c3) << endl;   // 5 < 3? false
    cout << "c3 > c2: " << (c3 > c2) << endl;   // true
    cout << "c1 <= c3: " << (c1 <= c3) << endl; // 3+4i <= 3+4i true
    cout << "c3 >= c2: " << (c3 >= c2) << endl; // true
    cout << "c1 == c1: " << (c1 == c1) << endl; // true
    cout << "c1 != c3: " << (c1 != c3) << endl; // true

    // Test getters
    cout << "c3.getRe(): " << c3.getRe() << endl;
    cout << "c3.getIm(): " << c3.getIm() << endl;

    // Test setters
    c1.setRe(10);
    c1.setIm(20);
    cout << "c1 after setRe(10), setIm(20): ";
    c1.printOn(cout) << endl;

    return 0;
}
