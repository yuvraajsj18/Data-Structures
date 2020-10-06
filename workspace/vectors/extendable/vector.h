// Extendable array based vector

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template <typename type>
class Vector
{
    private:
        int capacity;   // total array size
        int num_elements;   // number of elements in vector
        type *vector;   // array to store vector's element
    public:
        Vector(); 
        Vector(const Vector<type>& vect);  
        ~Vector();

        Vector<type>& operator=(const Vector<type>& vect);

        inline int size() const; // number of elements
        inline bool empty() const;
        type& operator[](const int index);    // for indexing
        type& at(const int index);    // same as [] but throw out_of_range if i out of range
        type erase(const int index); // remove element at i index and return it, throw out_of_range if i outofrange
        void insert(const int index, const type& element);    // insert element at index i shift other right
        void reserve(const int new_capasity);
        void display();
};

#include "vector.tpp"
#endif