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

        /*
        delete (L1, K), where L1 is a circular linked list of integers and K is an
        integer, to delete all occurrences of node with the value K.
        */
        static void delete_all(Clist<type> &L1, type K);

        // Write a member function to concatenate two singly circular linked lists.
        void concat(const Clist<type> &l2);

        /*
        Write a member function to delete the ith element in a singly circular linked list. The position
        i is passed as a parameter to this function.
        */
       void remove(int i);
};

#include "clist.tpp"
#endif