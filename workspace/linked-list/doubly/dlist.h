#ifndef DLIST_H
#define DLIST_H

#include <iostream>
using namespace std;

template <typename type>
class Dlist;

/*
 *  Node for a double link list
 *  It is a template class with a member to store relevent data,
 *  and a previous and next pointer to connnect to different nodes.
 */
template <typename type>
class Node
{
    private:
        type data;
        Node<type> *previous;
        Node<type> *next;
        friend class Dlist<type>;
    public:
        Node(type data, Node<type> *previous=nullptr, Node<type> *next=nullptr)
        {
            this->data = data;
            this->previous = previous;
            this->next = next;
        }
};

/*
 *  a Doubly Linked List
 *  with relevent functions
 */
template <typename type>
class Dlist
{
    private:
        Node<type> *head;
        Node<type> *tail;

    public:
        Dlist();
        ~Dlist();

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
};

#include "dlist.tpp"
#endif