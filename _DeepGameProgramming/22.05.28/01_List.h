//* 202131230 정윤혁 2022.05.28

#ifndef LIST_H
#define LIST_H

#include <cassert>
#include <iostream>

using namespace std;

template <typename T> struct Node
{
    T data;
    Node<T> *next;
};

template <typename T> class List
{
  private:
    Node<T> *begin;
    int count;
    Node<T> *makeNode(const T &value);

  public:
    List();
    ~List();
    void insert(int pos, const T &value);
    void erase(int pos);
    T &get(int pos) const;
    void print() const;
    int size() const;
};
#endif