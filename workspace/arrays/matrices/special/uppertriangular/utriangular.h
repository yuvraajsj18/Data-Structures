#ifndef UTRIANGULAR_H
#define UTRIANGULAR_H

#include <iostream>
#include <stdexcept>

template <typename type>
class UTriangularMatrix
{
    private:
        int n;  // dimension
        type* elements; // elements in upper triangular

    public:
        UTriangularMatrix(int n = 5);
        ~UTriangularMatrix();

        inline type get(int i, int j) const;    // Throw std::out_of_range
        inline void set(int i, int j, const type& value);   // Throw std::out_of_range and std::invalid_arguments

        void input();
        void display();
};

#include "utriangular.tpp"
#endif