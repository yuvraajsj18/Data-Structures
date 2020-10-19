#ifndef SYMMETRICMATRIX_H
#define SYMMETRICMATRIX_H

#include <iostream>
#include <stdexcept>

template <typename type>
class SymmetricMatrix
{
    private:
        int n;  // dimension
        type* elements; // elements in upper triangular

    public:
        SymmetricMatrix(int n = 5);
        ~SymmetricMatrix();

        inline type get(int i, int j) const;    // Throw std::out_of_range
        inline void set(int i, int j, const type& value);   // Throw std::out_of_range and std::invalid_arguments

        void input();
        void display();
};

#include "symmetricmatrix.tpp"
#endif