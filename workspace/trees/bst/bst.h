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
        BSTNode<type>* search(BSTNode<type>* node, const type& key) const;
        void preorder(BSTNode<type>* node);
        void inorder(BSTNode<type>* node);  
        void postorder(BSTNode<type>* node);  
        void visit(BSTNode<type>* node);

    public:
        BST();
        ~BST();

        inline void clear();
        inline bool empty() const;

        void insert(const type& key);

        void find_del_copy(const type& key);
        void del_copy(BSTNode<type>*& node);

        void find_del_merge(const type& key);
        void del_merge(BSTNode<type>*& node);

        BSTNode<type>* search(const type& key) const;
        void change_key(const type& key, const type& new_key);   // search for a key and change its value and place its node appropriately.

        // Display all nodes -
        void preorder();
        void inorder();
        void postorder();
        void breadth_first();
};

#include "bst.tpp"
#endif
