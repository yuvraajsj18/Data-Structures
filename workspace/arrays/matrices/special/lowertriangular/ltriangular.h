#ifndef LTRIANGULAR_H
#define LTRIANGULAR_H

#include <iostream>
#include <stdexcept>

template <typename type>
class LTriangularMatrix
{
    private:
        int n;  // dimension
        type* elements; // elements in upper triangular

    public:
        LTriangularMatrix(int n = 5);
        ~LTriangularMatrix();

        inline type get(int i, int j) const;    // Throw std::out_of_range
        inline void set(int i, int j, const type& value);   // Throw std::out_of_range and std::invalid_arguments

        void input();
        void display();
};

#include "ltriangular.tpp"
#endif