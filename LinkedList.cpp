#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
    head = nullptr;

    ListItem<T> *temp = otherLinkedList.head;
    while (temp != nullptr)
    {
        insertAtTail(temp->value);
        temp = temp->next;
    }

}

template <class T>
LinkedList<T>::~LinkedList()
{
    ListItem<T> *current;
    while (head != nullptr)
    {
        current = head;
        head = head->next;
        delete current;
    }
}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
    ListItem<T> *temp = new ListItem<T>(item);

    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
    ListItem<T> *temp = new ListItem<T>(item);
    ListItem<T> *current = head;

    if (head == nullptr)
    {
        head = temp;
    }

    else
    {
        // traverse the list and get to the tail
        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = temp;
        temp->prev = current;   
    }  
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
    ListItem<T> *temp = new ListItem<T>(toInsert);

    if (head == nullptr)
    {
        cout << "List is empty. Terminating\n";
        exit(1);
    }

    // find the node to insert after
    ListItem<T> *current = new ListItem<T>(0);
    current = head;

    while (current->value != afterWhat)
    {
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;
    temp->prev = current;
}


template <class T>
ListItem<T>* LinkedList<T>::getHead() const
{
    return head;
}

template <class T>
ListItem<T>* LinkedList<T>::getTail() const
{
   ListItem<T> *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    return current;
}
    


template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    ListItem<T> *current = head;
    bool found = false;
    while (current != nullptr)
    {
        if (current->value == item)
        {
            found = true;
            break;
        }
        current = current->next;
    }

    if (found)
        return current;
    else
        return nullptr;
}

template <class T>
void LinkedList<T>::deleteElement(T item)
{
    if (head == nullptr)
    {
        cout << "List is empty! Cant delete from empty list\n";
        return;
    }

    else if (searchFor(item))
    {
            
        ListItem<T> *current = searchFor(item);

        if (current->next != nullptr && current->prev != nullptr)
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            current = nullptr;
        }
        else if(current->prev == nullptr)
        {
            deleteHead();
        }
        else
        {
            deleteTail();
        }
        
    }

    else
    {
        cout << "Value not found!\n";
        return;
    }
}

template <class T>
void LinkedList<T>::deleteHead()
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete from empty list!\n";
        return;
    }

    ListItem<T> *temp = head;

    if (length() == 1)
    {
        delete temp;
        head = nullptr;
    }
    else
    {
        head->next->prev = nullptr;
        head = head->next;
        delete temp;
        temp = nullptr;     
    }
    
   
}

template <class T>
void LinkedList<T>::deleteTail()
{
    if (length() == 0)
    {
        cout << "Can't delete from an empty list!\n";
        return;
    }
    if (head == nullptr)
    {
        cout << "List is empty and has no tail. Cannot delete!\n";
        return;
    }

    ListItem<T> *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    if (current->prev == nullptr)
    {
        deleteHead();
    }
    else
    {
        // make the previous node point to null
        current->prev->next = nullptr;
        delete current;
        current = nullptr;
        
    }
    
   
}

template <class T>
int LinkedList<T>::length()
{
    int len = 0;
    if (head == nullptr)
        return 0;
    else
    {
        ListItem<T> *temp = head;
        while (temp != nullptr)
        {
            len += 1;
            temp = temp->next;
        }
        return len;
    }
    
}
template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<float>;
template class LinkedList<char>;

#endif
