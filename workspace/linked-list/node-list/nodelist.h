#ifndef NODELIST_H
#define NODELIST_H

#include <iostream>
#include <stdexcept>

template <typename type>
class NodeList
{
    private:
        class Node;

        Node<type> *header;   // Sentinel
        Node<type> *trailer;  // Sentinel
        int num_elements;
    public:
        class Iterator;

        NodeList();
        ~NodeList();
        NodeList(const NodeList<type>& that);
        NodeList<type>& operator=(const NodeList<type>& that);

        inline int size() const;
        inline bool empty() const;
        inline Iterator begin() const;
        inline Iterator end() const;
        void insert_front(const type& element);
        void insert_back(const type& element);
        void insert(const Iterator& position, const type& element); // insert before position
        type eraseFront();
        type eraseBack();
        type erase(const Iterator& position);
};

template <typename type>
class NodeList<type> :: Node
{
    private:
        type data;
        Node* previous;
        Node* next;
        friend class NodeList<type>;
    public:
        Node(const type& data, Node* previous=nullptr, Node* next=nullptr);
};

template <typename type>
class NodeList<type> :: Iterator
{
    private:
        Node<type>* node;
        Iterator(Node* node);
        friend class NodeList<type>;

    public:
        type& operator*(); 
        bool operator==(const Iterator& that) const;
        bool operator!=(const Iterator& that) const;
        Iterator& operator++();
        Iterator& operator--();       
};

#include "nodelist.tpp"
#endif