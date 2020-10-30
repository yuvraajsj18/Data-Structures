#include "sequence.h"

template <typename type>
typename NodeSequence<type>::Iterator NodeSequence<type>::at_index(int index) const
{
    if (index < 0 || index > NodeSequence<type>::size())
        throw std::runtime_error("Illegal index in at_index()");
    
    typename NodeSequence<type>::Iterator position = NodeSequence<type>::begin();
    for (int count = 0; count < index; count++)
        ++position;

    return position;
}

template <typename type>
int NodeSequence<type>::index_of(const typename NodeSequence<type>::Iterator& position) const
{
    int count = 0;
    typename NodeSequence<type>::Iterator temp = NodeSequence<type>::begin();
    for (; temp != NodeSequence<type>::end() && temp != position; ++temp)
        count++;

    if (temp == NodeSequence<type>::end())
        throw std::runtime_error("Invalid position in index_of()");

    return count;
}
