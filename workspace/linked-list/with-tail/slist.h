#ifndef SLIST_H
#define SLIST_H

#include <iostream>
using namespace std;

template <typename type>
class Slist;    // forward declaration for use in Node as friend

// node in a linked list
template <typename type>
class Node
{
    private:
        type data;
        Node<type> *next;
        friend class Slist<type>;

    public:
        Node(type data, Node<type> *next = NULL)
        {
            this -> data = data;
            this -> next = next;
        }
};

// Singly list class that defines all the operation
template <typename type>
class Slist
{
    private:
        Node<type> *head;   // points the head of the linked list
        Node<type> *tail;   // points the tail of the linked list

    public:
        Slist();
        ~Slist();

        bool is_empty();
        void add_head(type element);
        void add_tail(type element);
        type delete_head();
        type delete_tail();
        void delete_node(type element);
        bool search(type element);
        int count_node();
        void display();
        void reverse();
};

#include "slist.tpp"
#endif