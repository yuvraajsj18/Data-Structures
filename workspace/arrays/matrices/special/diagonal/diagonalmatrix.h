#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H

#include <iostream>
#include <stdexcept>

template <typename type>
class DiagonalMatrix
{
    private:
        int n;  // matrix dimension
        type* diagonal; // stores diagonal elements
    public:
        DiagonalMatrix(int n = 5);
        ~DiagonalMatrix();

        inline type get(int i, int j) const;   // throw out of range error if index illegal
        inline void set(int i, int j, const type& value);  // throw out of range error if index illegal and invalid argument error if value is non zero for non diagonal elements

        void input();
        void display();
};

#include "diagonalmatrix.tpp"
#endif

/*
    A Diagonal matrix is of the form 
    1 0 0
    0 2 0
    0 0 3
    with all non diagonal elements set to 0.
    therefore we only need to store the diagonal elements
    that we can do space efficiently with a 1 dimensional array
    where [i][j] element is mapped to i - 1 if i == j (diagonal element)
    otherwise mapped to 0.
*/
