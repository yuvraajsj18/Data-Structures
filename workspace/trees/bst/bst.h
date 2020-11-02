#ifndef BST_H
#define BST_H

template <typename type>
class BST;

template <typename type>
class BSTNode
{
    private:
        type key;
        BSTNode<type>* left;
        BSTNode<type>* right;

    public:
        BSTNode();
        BSTNode(const type& key, BSTNode<type>* left=nullptr, BSTNode<type>* right=nullptr);
};

template <typename type>
class BST
{
    private:
        BSTNode<type>* root;

        void clear(BSTNode<type>* node);
    
    public:
        BST();
        ~BST();

        void clear();

        void insert(const type& key);

        void find_del_copy(const type& key);
        void del_copy(BSTNode<type>*& node);

        void find_del_merge(const type& key);
        void del_merge(BSTNode<type>*& node);
};

#include "bst.tpp"
#endif
