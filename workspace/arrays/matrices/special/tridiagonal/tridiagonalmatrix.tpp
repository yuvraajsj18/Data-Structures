#include "tridiagonalmatrix.h"

template <typename type>
TridiagonalMatrix<type>::TridiagonalMatrix(int n)
{
    this->n = n;
    tridiagonals = new type[3 * n - 2];
}

template <typename type>
TridiagonalMatrix<type>::~TridiagonalMatrix()
{
    delete[] tridiagonals;
}

template <typename type>
inline type TridiagonalMatrix<type>::get(int i, int j) const
{
    if (i < 1 || j < 1 || i > n || j > n)
        throw std::out_of_range("Illegal index in get()");

    switch(i - j)
    {
        case 1: // lower diagonal
            return tridiagonals[i - 2];
        case 0: // main diagonal
            return tridiagonals[n + i - 2];
        case -1: // upper diagonal
            return tridiagonals[2 * n + i - 2];
        default:
            return 0;   // all non tridiagonal elements
    }
}

template <typename type>
inline void TridiagonalMatrix<type>::set(int i, int j, const type& value)
{
    if (i < 1 || j < 1 || i > n || j > n)
        throw std::out_of_range("Illegal index in set()");

    switch(i - j)
    {
        case 1:     // lower diagonal
            tridiagonals[i - 2] = value;
        break;
        case 0:     // main diagonal
            tridiagonals[n + i - 2] = value;
        break;
        case -1:    // upper diagonal
            tridiagonals[2 * n + i - 2] = value;
        break;
        default:    // 
            if (value != 0) 
                throw std::invalid_argument("Non tridiagonal elements can only be 0");
        break;
    }
}

template <typename type>
void TridiagonalMatrix<type>::input()
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
void TridiagonalMatrix<type>::display()
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
