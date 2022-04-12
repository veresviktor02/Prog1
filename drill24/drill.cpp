#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>

using namespace Numeric_lib;

void my_sizeof()
{
    cout << "sizeof(char): " << sizeof(char) << '\n';
    cout << "sizeof(short): " << sizeof(short) << '\n';
    cout << "sizeof(int): " << sizeof(int) << '\n';
    cout << "sizeof(long): " << sizeof(long) << '\n';
    cout << "sizeof(float): " << sizeof(float) << '\n';
    cout << "sizeof(double): " << sizeof(double) << '\n';
    cout << "sizeof(int*): " << sizeof(int*) << '\n';
    cout << "sizeof(double*): " << sizeof(double*) << '\n';

    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);

    cout << "sizeof(Matrix<int> a(10)): " << sizeof(a) << '\n';
    cout << "sizeof(Matrix<int> b(100)): " << sizeof(b) << '\n';
    cout << "sizeof(Matrix<double> c(10)): " << sizeof(c) << '\n';
    cout << "sizeof(Matrix<int,2> d(10,10)): " << sizeof(d) << '\n';
    cout << "sizeof(Matrix<int,3> e(10,10,10)): " << sizeof(e) << '\n';
}

void my_sqrt()
{
    cout << "Add numbers, that the program will put in a 'sqrt()':\n"; 

    int s;
    while(cin >> s)
    {
        if(s < 0)
        {
            cout << "no square root" << '\n';
        }
        else
        {
            cout << "sqrt of s: "  << sqrt(s) << '\n';
        }
    }
}

void my_matrix()
{
    Matrix<double> Neo(10);
    float number;
    for(int i = 0; i < 10; i++)
    {
        cout << i+1 << ". szám: ";
        number = 0;
        cin >> number;
        Neo[i] = number;
    }

    for(int i = 0; i < 10; i++)
    {
        cout << Neo[i] << ' ';
    }
    cout << '\n';
}

void my_complex() //nem ártana tesztelni ezt a fv-t!
{
    Matrix<complex<double>> Neo(10);
    complex<double> s;
    for(int i = 0; i < 10; i++)
    {
        cout << i+1 << ". komplex szám: ";
        cin >> s;
        Neo[i] = s;
    }

    complex<double> sum = 0;

    for(int i = 0; i < 10; i++)
    {
        sum = sum + Neo[i];
    }

    cout << "Sum of 'Matrix<complex<double>>' : " << sum << '\n';
}

void my_matrix2() //fix needed! for-t kell ágyazni for-ba, de már nincs idő az órán :(
{
    Matrix<int, 2> m(2, 3);
    int s;

    cout << "Adj meg 6 számot a mátrixnak:\n";

    for(int i = 0; i < 6; i++)
    {
        cin >> s;
        m[i] = s;
    }

    for(int i = 0; i < 6; i++)
    {
        cout << m[i] << ' ';
    }
    cout << '\n';

    //terminate called after throwing an instance of 'Numeric_lib::Matrix_error' Félbeszakítva (core készült)
}

int main()
{
    my_sizeof();

    my_sqrt();

    my_matrix();

    my_complex();

    my_matrix2();

    return 0;
}

/*
    1. Print the size of a char, a short, an int, a long, a float, a double, an int*, and a double* (use sizeof, not <limits>).
    2. Print out the size as reported by sizeof of Matrix<int> a(10), Matrix<int> b(100), Matrix<double> c(10), Matrix<int,2> d(10,10), Matrix<int,3> e(10,10,10).
3. Print out the number of elements of each of the Matrix es from 2.
    4. Write a program that takes int s from cin and outputs the sqrt() of each int, or “no square root” if sqrt(x) is illegal for some x (i.e., check your sqrt() return values).
    5. Read ten floating-point values from input and put them into a Matrix<double>.
    (Matrix has no push_back() so be careful to handle an attempt to enter a wrong number of double s.)
    Print out the Matrix .
6. Compute a multiplication table for [0,n)*[0,m) and represent it as a 2D Matrix.
Take n and m from cin and print out the table nicely (assume that m is small enough that the results fit on a line).
7. Read ten complex<double> s from cin (yes, cin supports >> for complex ) and put them into a Matrix . 
Calculate and output the sum of the ten complex numbers.
8. Read six int s into a Matrix<int,2> m(2,3) and print them out.
*/