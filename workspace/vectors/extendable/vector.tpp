#include "vector.h"

template <typename type>
Vector<type> :: Vector()
{
    capacity = 0;
    num_elements = 0;
    vector = nullptr;
}

template <typename type>
Vector<type> :: ~Vector()
{
    if (vector != nullptr)
        delete[] vector;
}

template <typename type>
Vector<type> :: Vector(const Vector<type> &vect)
{
    capacity = vect.capacity;
    num_elements = vect.num_elements;
    vector = new type[capacity];
    for (int i = 0; i < num_elements; i++)
        vector[i] = vect.vector[i];
}

template <typename type>
Vector<type>& Vector<type> :: operator=(const Vector<type> &vect)
{
    if (vector != nullptr)
        delete[] vector;    // delete old vector
    
    capacity = vect.capacity;
    num_elements = vect.num_elements;
    vector = new type[capacity];
    for (int i = 0; i < num_elements; i++)
        vector[i] = vect.vector[i];

    return *this;
}

template <typename type>
inline int Vector<type> :: size() const
{
    return num_elements;
}

template <typename type>
inline bool Vector<type> :: empty() const
{
    return size() == 0;
}

template <typename type>
type& Vector<type> :: operator[](const int index)
{
    return vector[index];
}

template <typename type>
type& Vector<type> :: at(const int index)
{
    if (index < 0 || index >= size())
        throw out_of_range("Illegal index in function at()");

    return vector[index];
}

template <typename type>
type Vector<type> :: erase(const int index)
{
    if (index < 0 || index >= size())
        throw out_of_range("Illegal index in function at()");
    
    type to_delete = vector[index];
    // shift elements above 'index' to the left
    for (int i = index + 1; i < size(); i++)
        vector[i - 1] = vector[i]; 
    
    num_elements--;

    return to_delete;
}

template <typename type>
void Vector<type> :: insert(const int index, const type &element)
{
    if (num_elements >= capacity)
        reserve(max(1, 2 * capacity));

    // shift elements right of 'index'
    for (int i = size() - 1; i >= index; i--)
        vector[i + 1] = vector[i];
    
    // fill the hole
    vector[index] = element;
    num_elements++; 
}


template <typename type>
void Vector<type> :: reserve(const int new_capacity)
{
    if (new_capacity <= capacity)
        return;    

    type *new_vector = new type[new_capacity];
    for (int i = 0; i < size(); i++)    // copy elements to new vector
        new_vector[i] = vector[i];
    
    if (vector != nullptr)
        delete[] vector;

    vector = new_vector;
    capacity = new_capacity;
}

template <typename type>
void Vector<type> :: display()
{
    for (int i = 0; i < size(); i++)
        cout << vector[i] << " ";
    
    cout << "\n";
}
