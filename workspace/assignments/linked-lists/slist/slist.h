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
        void concat(Slist<type> &s1, Slist<type> &s2);
        Slist<type> operator+(Slist<type> &s);
        Slist<type>& operator=(const Slist<type> &s);
        // TODO
        void insert(type element, int position);
        void remove(int position);
        Node<type>* searchNode(type element);

        // delete every third element from the list
        void delete_three();

        // compare two lists
        bool is_same(const Slist<type> &list);
};

#include "slist.tpp"
#endif