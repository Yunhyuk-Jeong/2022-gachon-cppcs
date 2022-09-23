//* 202131230 정윤혁 2022.05.28

#ifndef STACK_CPP
#define STACK_CPP

#include "../22.05.28/03_Stack.h"

template <typename T> void Stack<T>::push(const T &value)
{
    list.insert(0, value);
}

template <typename T> void Stack<T>::pop()
{
    list.erase(0);
}

template <typename T> T &Stack<T>::top() const
{
    return list.get(0);
}

template <typename T> int Stack<T>::size() const
{
    return list.size();
}
#endif