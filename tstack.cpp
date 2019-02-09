#include "LinkedList.cpp"
#include <iostream>
using namespace std;

/* This is the generic Stack class */
template <class T>
class Stack
{
    LinkedList<T> list;

  public:

    // Constructor
    Stack();

    // Copy Constructor
    Stack(const Stack<T>& otherStack);

    // Destructor
    ~Stack();

    // Required Methods
    void push(T item);
    T top();
    T pop();
    int length();
    bool isEmpty();

    void print();
};


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

template <class T>
void Stack<T>::print()
{
    ListItem<T> *temp = this->list.getHead();
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

int main()
{
    Stack<int> s;
    
    for (int i = 20; i >= 0; i--)
    {
        s.push(i);
    }


    int ten = s.top();
    cout << "Top val: " << ten << endl;

    Stack<int> s2(s);

    s.print();
    cout << "\n here's stack2: " << endl;
    s2.print();
    cout << endl;
    cout << endl;
}