#ifndef OLIST_H
#define OLIST_H

#include <iostream>
using namespace std;

template <typename type>
class Olist;

template <typename type>
class Node
{
    private:
        type data;
        Node<type> *next;
        friend class Olist<type>;
    
    public:
        Node(type data, Node<type> *next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
};

template <typename type>
class Olist
{
    private:
        Node<type> *head;

    public:
        Olist();
        ~Olist();

        bool isempty();
        void insert(type element);
        void delete_node(type element);
        void display();
        bool search(type element);
        void merge(Olist<type> &l1, Olist<type> &l2);
};

#include "olist.tpp"
#endif
