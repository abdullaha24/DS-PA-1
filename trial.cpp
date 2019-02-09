#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

class list
{
private: 
    node *head;
public:
    list() {head = nullptr;}
    void insertHead(int v)
    {
        node *temp = new node;
        temp->data = v;
        temp->next = nullptr;
        temp->prev = nullptr;

        if (head == NULL)
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

    void print()
    {
        node *temp = new node;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void insertTail(int  v)
    {
        node * temp = new node;
        temp = head;

        node *current = new node;
        current->data = v;
        current->next = nullptr;
        current->prev = nullptr;

        if (head == nullptr)
        {
            head = current;
        }

        else
        {
            while (temp->next != nullptr)
            {
                temp = temp->next;
            } 

            temp->next = current;
            current->prev = temp;
        }
        
    }

    void insertAfter(int w, int aw)
    {
        node *temp = new node;
        temp->data = w;
        temp->prev = nullptr;
        temp->next = nullptr;

        node *current = new node;
        current = head;

        while (current->data != aw)
        {
            current = current->next;
        }

        temp->next = current->next;
        current->next = temp;
        temp->prev = current;
    }

    void deleteTail()
    {
        node *current = new node;
        current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->prev->next = nullptr;
        current->prev = nullptr;
    }

    void deleteHead()
    {
        head = head->next;
       // head->prev = nullptr;
    }

    int length()
    {
        int len = 0;
        node *temp = new node;
        temp = head;

        while (temp!= nullptr)
        {
            len += 1;
            temp = temp->next;
        }
        return len;
    }

    node * searchFor(int v)
    {
        bool found = false; 
        node *current = head;
        while (current != nullptr)
        {
            if (current->data == v)
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

    node *getHead()
    {
        return head;
    }

    node *getTail()
    {
        node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        return temp;
    }

    ~list()
    {
        node *current = head;
        while (current)
        {
            node *next = current->next;
            delete current;
            current = next;
        }
    }

    list(const list & other)
    {
        head = nullptr;
        node * temp = new node;
        temp = other.head;

        while (temp!= nullptr)
        {
            insertTail(temp->data);
            temp = temp->next;
        }
    }

    void deleteElement(int v)
    {
        if (searchFor(v))
        {
            node *temp = searchFor(v);
            if (temp->next != nullptr)
            {
                temp->prev->next = temp -> next;
                temp->next->prev = temp->prev;
            }
            else
            {
                deleteTail();
            }
            

        }
        else
        {
            cout << "Element not found in list!\n";
            return;
        }
      
    }
};

int main()
{
    list l;
    l.deleteTail();

}