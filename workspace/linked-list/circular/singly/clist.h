#ifndef CLIST_H
#define CLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename type>
class Clist;

template <typename type>
class Node
{
    private:
        type data;
        Node<type>* next;
        friend class Clist<type>;

    public:
        Node(type data, Node<type> *next = nullptr)
        {
            this->data = data; 
            this->next = next;
        }
};

template <typename type>
class Clist
{
    private:
        Node<type> *tail;
    
    public:
        Clist();
        ~Clist();
        
        bool isempty();

        void add_head(type element);
        void add_tail(type element);

        type delete_head();
        type delete_tail();
        void delete_node(type element);

        bool search(type element);
        int count_node();
        void display();
        void reverse();

        void remove(int i);
        void concat(const Clist<type> &l2);

        void insert(type x, type y);
        Node<type>* searchNode(type element);

        int count_key(type x);

};

#include "clist.tpp"
#endif