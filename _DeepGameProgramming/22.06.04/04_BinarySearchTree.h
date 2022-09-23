//* 202131230 정윤혁 2022.06.04

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <cassert>
#include <iostream>

using namespace std;

template <class T> struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

template <class T> class BinarySearchTree
{
  private:
    Node<T> *root;
    int count;
    Node<T> *makeNode(const T &value);
    void destroy(Node<T> *ptr);
    void insert(const T &value, Node<T> *&ptr);
    void inorder(Node<T> *ptr) const;
    void preorder(Node<T> *ptr) const;
    void postorder(Node<T> *ptr) const;
    bool search(const T &value, Node<T> *ptr) const;

  public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(const T &value);
    void erase(const T &value);
    bool search(const T &value) const;
    void inorder() const;
    void preorder() const;
    void postorder() const;
    int size() const;
    bool empty() const;
};
#endif