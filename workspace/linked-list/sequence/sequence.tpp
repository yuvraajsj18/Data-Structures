#include "sequence.h"

template <typename type>
typename NodeSequence<type>::Iterator NodeSequence<type>::at_index(int index) const
{
    if (index < 0 || index > this->size())
        throw std::runtime_error("Illegal index in at_index()");
    
    typename NodeSequence<type>::Iterator position = this->begin();
    for (int count = 0; count < index; count++)
        ++position;

    return position;
}

template <typename type>
int NodeSequence<type>::index_of(const typename NodeSequence<type>::Iterator& position) const
{
    int count = 0;
    typename NodeSequence<type>::Iterator temp = this->begin();
    for (; temp != this->end() && temp != position; ++temp)
        count++;

    if (temp == this->end())
        throw std::runtime_error("Invalid position in index_of()");

    return count;
}

/*

Why this->func_name() instread of func_name in derived template class --

https://gcc.gnu.org/onlinedocs/gcc-3.4.0/gcc/Name-lookup.html

*/
