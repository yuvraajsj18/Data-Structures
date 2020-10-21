#ifndef DCLIST_H
#define DCLIST_H

#include <iostream>
#include <stdexcept>

template <typename type>
class Node
{
    private:
        Node* previous;
        Node* next;
        type data;

    public:
        Node(const type& data, Node* previous=nullptr, Node* next=nullptr);
};

template <typename type>
class DCList
{
    private:
        Node* tail;
    
    public:
        DCList();
        ~DCList();

        void insert_front(const type& element);
        void insert_after(const type& after, const type& element);
        void insert_back(const type& element);
        
        type remove_back();
        type remove_front();
        type remove_element(const type& element);

        Node<type>* search_node(const type& element);
        void concat(const DCList<type>& with);

        void display();
        int count();
};

#include "dclist.tpp"
#endif