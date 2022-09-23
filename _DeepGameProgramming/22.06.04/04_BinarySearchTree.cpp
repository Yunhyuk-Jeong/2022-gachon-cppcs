//* 202131230 정윤혁 2022.06.04

#ifndef BINARYSEARCHTREE_CPP
#define BINARYSEARCHTREE_CPP
#include "../22.06.04/04_BinarySearchTree.h"

template <class T> BinarySearchTree<T>::BinarySearchTree() : root(0), count(0)
{
}

template <class T> BinarySearchTree<T>::~BinarySearchTree()
{
    destroy(root);
}

template <class T> void BinarySearchTree<T>::insert(const T &value)
{
    insert(value, root);
    count++;
}

template <class T> bool BinarySearchTree<T>::search(const T &value) const
{
    return search(value, root);
}

template <class T> void BinarySearchTree<T>::preorder() const
{
    preorder(root);
}

template <class T> void BinarySearchTree<T>::inorder() const
{
    inorder(root);
}

template <class T> void BinarySearchTree<T>::postorder() const
{
    postorder(root);
}

template <class T> int BinarySearchTree<T>::size() const
{
    return count;
}

template <class T> bool BinarySearchTree<T>::empty() const
{
    return (count == 0);
}
template <class T> void BinarySearchTree<T>::destroy(Node<T> *ptr)
{
    if (!ptr)
        return;

    destroy(ptr->left);
    destroy(ptr->right);
    delete ptr;
}

template <class T> void BinarySearchTree<T>::insert(const T &value, Node<T> *&ptr)
{
    if (!ptr)
    {
        ptr = makeNode(value);
        return;
    }
    else if (value < ptr->data)
        insert(value, ptr->left);
    else
        insert(value, ptr->right);
}

template <typename T> void BinarySearchTree<T>::preorder(Node<T> *ptr) const
{
    if (!ptr)
        return;
    cout << ptr->data << endl;
    preorder(ptr->left);
    preorder(ptr->right);
}

template <class T> void BinarySearchTree<T>::inorder(Node<T> *ptr) const
{
    if (!ptr)
        return;
    inorder(ptr->left);
    cout << ptr->data << endl;
    inorder(ptr->right);
}

template <class T> void BinarySearchTree<T>::postorder(Node<T> *ptr) const
{
    if (!ptr)
        return;
    postorder(ptr->right);
    postorder(ptr->left);
    cout << ptr->data << endl;
}

template <typename T> bool BinarySearchTree<T>::search(const T &value, Node<T> *ptr) const
{
    if (!ptr)
        return false;
    else if (ptr->data == value)
        return true;
    else if (value < ptr->data)
        return search(value, ptr->left);
    else
        return search(value, ptr->right);
}

template <typename T> Node<T> *BinarySearchTree<T>::makeNode(const T &value)
{
    Node<T> *temp = new Node<T>;
    temp->data = value;
    temp->left = 0;
    temp->right = 0;
    return temp;
}
#endif