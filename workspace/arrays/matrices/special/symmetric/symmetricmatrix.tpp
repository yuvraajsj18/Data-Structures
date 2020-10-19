#include <iostream>
#include "symmetricmatrix.h"

template <typename type>
SymmetricMatrix<type>::SymmetricMatrix(int n)
{
    this->n = n;
    elements = new type[(n * (n + 1)) / 2];
}

template <typename type>
SymmetricMatrix<type>::~SymmetricMatrix()
{
    delete[] elements;
}

template <typename type>
inline type SymmetricMatrix<type>::get(int i, int j) const 
{
    if (i < 1 || j < 1 || i > n || j > n)
        throw std::out_of_range("Illegal index in get()");
    
    if (j >= i)
        return elements[((j * (j - 1))/ 2 + (i - 1))];
    else 
        return elements[((i * (i - 1) / 2 + (j - 1)))];  // return [i][j] for [j][i]
}

template <typename type>
inline void SymmetricMatrix<type>::set(int i, int j, const type& value)
{
    if (i < 1 || j < 1 || i > n || j > n)
        throw std::out_of_range("Illegal index in set()");
    
    if (j >= i)
        elements[((j * (j - 1))/ 2 + (i - 1))] = value;
    else if (value != elements[((i * (i - 1) / 2 + (j - 1)))]) // [i][j] != [j][i]
        throw std::invalid_argument("Not symmetric element entered");
}

template <typename type>
void SymmetricMatrix<type>::input()
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
void SymmetricMatrix<type>::display()
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
