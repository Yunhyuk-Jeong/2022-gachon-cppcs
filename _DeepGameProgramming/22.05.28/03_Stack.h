//* 202131230 정윤혁 2022.05.28

#ifndef STACK_H
#define STACK_H

#include "../22.05.28/01_List.cpp"

template <typename T> class Stack
{
  private:
    List<T> list;

  public:
    void push(const T &data);
    void pop();
    T &top() const;
    int size() const;
};
#endif