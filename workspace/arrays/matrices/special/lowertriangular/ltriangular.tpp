#include <iostream>
#include "ltriangular.h"

template <typename type>
LTriangularMatrix<type>::LTriangularMatrix(int n)
{
    this->n = n;
    elements = new type[(n * (n + 1)) / 2];
}

template <typename type>
LTriangularMatrix<type>::~LTriangularMatrix()
{
    delete[] elements;
}

template <typename type>
inline type LTriangularMatrix<type>::get(int i, int j) const 
{
    if (i < 1 || j < 1 || i > n || j > n)
        throw std::out_of_range("Illegal index in get()");
    
    if (i >= j)
        return elements[((i * (i -1)) / 2) + (j - 1)];
    else 
        return 0;
}

template <typename type>
inline void LTriangularMatrix<type>::set(int i, int j, const type& value)
{
    if (i < 1 || j < 1 || i > n || j > n)
        throw std::out_of_range("Illegal index in set()");
    
    if (i >= j)
        elements[((i * (i - 1))/ 2 + (j - 1))] = value;
    else if (value != 0)
        throw std::invalid_argument("Non upper triangular elements can only be 0");
}

template <typename type>
void LTriangularMatrix<type>::input()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int value;
            std::cout << "value at [" << i << "][" << j << "] = ";
            std::cin >> value;
            set(i, j, value);
        }
    }
}

template <typename type>
void LTriangularMatrix<type>::display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << get(i, j) << " ";
        }
        std::cout << "\n";
    }
}
