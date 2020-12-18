#ifndef BST_H
#define BST_H

#include <iostream>
#include <queue>

template <typename type>
class BST;

template <typename type>
class BSTNode
{
    private:
        type key;
        BSTNode<type>* left;
        BSTNode<type>* right;
        friend class BST<type>;

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
        BSTNode<type>* search(BSTNode<type>* node, const type& key) const;
        void inorder(BSTNode<type>* node);  
        inline void visit(BSTNode<type>* node) const;

        int sum_nonleaf(BSTNode<type>* node);     // part c

        void leaf_inorder(BSTNode<type>* node);     // part d

    public:
        BST();
        ~BST();

        inline void clear();
        inline bool empty() const;

        void insert(const type& key);       // part a

        void find_del_copy(const type& key);
        void del_copy(BSTNode<type>*& node);

        void find_del_merge(const type& key);
        void del_merge(BSTNode<type>*& node);

        BSTNode<type>* search(const type& key) const;  

        void inorder();     // part b

        inline int sum_nonleaf();     // part c

        void leaf_inorder();    // part d
};

#include "bst.tpp"
#endif
