#include "diagonalmatrix.h"

template <typename type>
DiagonalMatrix<type>::DiagonalMatrix(int n)
{
    this->n = n;
    diagonal = new type[n];
}

template <typename type>
DiagonalMatrix<type>::~DiagonalMatrix()
{
    delete[] diagonal;
}

template <typename type>
inline type DiagonalMatrix<type>::get(int i, int j) const
{
    if (i < 1 || j < 1 || i > n || j > n)
        throw std::out_of_range("Illegal index in get()");
    
    if (i == j)
        return diagonal[i - 1];
    else 
        return 0;
}

template <typename type>
inline void DiagonalMatrix<type>::set(int i, int j, const type& value)
{
    if (i < 1 || j < 1 || i > n || j > n)
        throw std::out_of_range("Illegal index in set()");
    
    if (i == j)
        diagonal[i - 1] = value;
    else if (value != 0)
        throw std::invalid_argument("Non diagonal elements must be zero");
}

template <typename type>
void DiagonalMatrix<type>::input()
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
void DiagonalMatrix<type>::display()
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