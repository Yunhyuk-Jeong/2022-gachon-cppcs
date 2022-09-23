//* 202131230 정윤혁 2022.06.04

#ifndef QUEUE_H
#define QUEUE_H
#include "../22.05.28/01_List.cpp"
template <class T> class Queue
{
  private:
    List<T> list;

  public:
    void push(const T &data);
    void pop();
    T &front() const;
    T &back() const;
    int size() const;
    void print() const;
};
#endif