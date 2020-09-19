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

        // Gives the middle element of the list by traversing the list only once. 
        type get_middle();

        // Delete all odd numbered nodes from the linked list
        void delete_odd();

        //  To overload the + operator on the doubly linked list
        Dlist<type> operator+(const Dlist<type> &list);
        Dlist<type>& operator=(const Dlist<type> &list);

        // To insert a node in the middle of the list using only one pass through the lists. If the list has odd
        // number of elements, it should be inserted after the middle element. 
        void set_middle(type element);

        // Insert an element X, at a given position i in the list.
        void insert(type element, int position);

        /*
            write a function to swap the kth node from the beginning of this list
            with the kth node from the end of the same list. The nodes have to be swapped and not just their
            contents
        */
       void swap_nodes(int k);
};

#include "dlist.tpp"
#endif