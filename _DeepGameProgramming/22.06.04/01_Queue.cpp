//* 202131230 정윤혁 2022.06.04

#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "../22.06.04/01_Queue.h"
#include "../22.05.28/01_List.cpp"

template <typename T> void Queue<T>::push(const T &value)
{
    list.insert(list.size(), value);
}

template <typename T> void Queue<T>::pop()
{
    list.erase(0);
}

template <typename T> T &Queue<T>::front() const
{
    return list.get(0);
}

template <typename T> T &Queue<T>::back() const
{
    return list.get(list.size() - 1);
}

template <typename T> int Queue<T>::size() const
{
    return list.size();
}

template <typename T> void Queue<T>::print() const
{
    list.print();
}
#endif