#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"
#include <iostream>
using namespace std;

template <class T>
Queue<T>::Queue()
{
    ListItem<T> *first = list.getHead();
    first = nullptr;
}
    
template <class T>
Queue<T>::Queue(const Queue<T>& otherQueue)
{
    ListItem<T> *current = otherQueue.list.getHead();
    while (current != nullptr)
    {
        list.insertAtTail(current->value);
        current = current->next;
    }
}

template <class T>
Queue<T>::~Queue()
{

}

template <class T>
void Queue<T>::enqueue(T item)
{
    list.insertAtTail(item);
}

template <class T>
T Queue<T>::front()
{
    T ret = list.getHead()->value;
    return ret;
}

template <class T>
T Queue<T>::dequeue()
{
    T ret = list.getHead()->value;
    list.deleteHead();
    return ret;
}

template <class T>
int Queue<T>::length()
{
	return list.length();
}

template <class T>
bool Queue<T>::isEmpty()
{
    return list.head == nullptr;
}


#endif
