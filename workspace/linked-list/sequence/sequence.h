#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "nodelist.h"
#include <iostream>
#include <stdexcept>

template <typename type>
class NodeSequence : public NodeList<type>
{
    public:
        typename NodeSequence<type>::Iterator at_index(int index) const;
        int index_of(const typename NodeSequence<type>::Iterator& position) const;
};

#include "sequence.tpp"
#endif