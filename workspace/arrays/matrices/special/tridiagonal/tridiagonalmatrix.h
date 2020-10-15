#ifndef TRIDIAGONALMATRIX_H
#define TRIDIAGONALMATRIX_H

#include <iostream>
#include <stdexcept>

template <typename type>
class TridiagonalMatrix
{
    private:
        int n;  // matrix dimension
        type* tridiagonals; // stores tridiagonal elemets
    public:
        TridiagonalMatrix(int n = 5);
        ~TridiagonalMatrix();

        inline type get(int i, int j) const;    // Throw std::out_of_range
        inline void set(int i, int j, const type& value);   // Throw std::out_of_range and std::invalid_arguments

        void input();
        void display();         
};

#include "tridiagonalmatrix.tpp"
#endif

/*
    A tridiagonal matrix is of the form
    1 2 0 0 0
    3 4 5 0 0
    0 6 7 8 0
    0 0 9 9 9
    0 0 0 8 3
    tridiagonal includes - the main diagonal, the diagonal above and below it
    all non-tridiagonal elements are 0
    total number of elements on tridiagonal are = n + (n - 1) + (n - 1) = 3n - 2

    We can store this matrix space efficiently in a 1D array by mapping by diagonals(below -> main -> above):
    below diagonal: [i][j] -> i - 2
    main diagonal: [i][j] -> n + i - 2
    above diagonal: [i][j] -> 2n + i - 2
    all other elements: value[i][j] = 0
*/