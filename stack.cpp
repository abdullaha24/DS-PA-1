#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"
#include <iostream>
using namespace std;

template <class T>
Stack<T>::Stack()
{
    ListItem<T> *first = list.getHead();
    first = nullptr;
}
    
template <class T>
Stack<T>::Stack(const Stack<T>& otherStack)
{
    ListItem<T> *current = otherStack.list.getHead();
    while (current != nullptr)
    {
        list.insertAtTail(current->value);
        current = current->next;
    }
}

template <class T>
Stack<T>::~Stack()
{
    
}

template <class T>
void Stack<T>::push(T item)
{
    list.insertAtHead(item);
}

template <class T>
T Stack<T>::top()
{
    T ret = list.getHead()->value;
    return ret;
}

template <class T>
T Stack<T>::pop()
{
    T ret = list.getHead()->value;
    list.deleteHead();
    return ret;
}

template <class T>
int Stack<T>::length()
{
    return list.length();
}

template <class T>
bool Stack<T>::isEmpty()
{
    return list.head == nullptr;
}

#endif