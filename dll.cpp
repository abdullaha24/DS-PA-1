#include <iostream>
using namespace std;

struct node
{
    int d;
    node *next;
    node *prev;
};

class dll
{
public:
    void destroy();
    void print();
    void insert(int v);
    void deleteNode(int v);
    dll();
    dll(const dll & otherlist);
    ~dll();
private:
    node *first, *last;
};

dll::dll()
{
    first = nullptr;
    last = nullptr;
}

void dll::destroy()
{
    node * temp;
    while (first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    last = nullptr;
}

void dll::print()
{
    node *current;
    current = first;
    while (current!=nullptr)
    {
        cout << current->d << " ";
        current = current->next;
    }
}

void dll::insert(int v)
{
    node *current;
    node *trailCurrent;
    node *newNode;
    bool found;

    newNode = new node;
    newNode->d = v;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (first == nullptr)
    {
        first = newNode;
        last = newNode;
    }
    else
    {
        found = false;
        current= first; 
        while (current!=nullptr && !found)
        {
            
        }
    }
    
}