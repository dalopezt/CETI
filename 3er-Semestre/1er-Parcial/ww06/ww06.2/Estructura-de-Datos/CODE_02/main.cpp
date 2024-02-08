/*
@author: David Alejandro López Torres
@id: 22310432
@date: Feb 6th, 2024
*/

#include <iostream>
using namespace std;

template<class T>
class Node 
{
    public:
    T value;
    Node* next;
    Node()
    {
        this->next = NULL;
    }
    Node(T value)
    {
        this->value = value;
        this->next = NULL;
    }
};

template<class T>
class List
{
    private:
    Node<T>* head;

    public:
    List()
    {
        head = NULL;
    }
    void ins(T value)
    {
        Node<T>* new_node = new Node<T>(value);
        if (head == NULL)
        {
            head = new_node;
            return;
        }

        Node<T>* aux = head;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = new_node;
    };
    void del(T value)
    {
        // Empty list
        if (head == NULL)
        {
            cout << "List empty" << endl;
            return;
        }
        
        Node<T>* aux = head;
        // Check if header is the match
        if (aux->value == value)
        {
            head = aux->next;
            delete aux;
            return;
        }

        // Move until aux->next has the value
        while (aux->next->value != value && aux->next != NULL)
        {
            aux = aux->next;
        }

        // If didn't match, abort
        if (aux->next == NULL)
        {
            cout << "Value not found" << endl;
            return;
        }

        // Otherwise
        Node<T>* temp = aux->next;
        aux->next = temp->next;
        delete temp;
    } 
    void display()
    {
        Node<T>* aux = head;
        while(aux != NULL)
        {
            cout << aux->value << endl;
            aux = aux->next;
        }
    }
};

int main()
{
    List<int> list;
    list.ins(1);
    list.ins(2);
    list.ins(3);
    list.ins(4);
    list.ins(5);
    cout << "Before delete" << endl;
    list.display();
    list.del(3);
    cout << "After first delete (3)" << endl;
    list.display();
    list.del(1);
    cout << "After second delete (1)" << endl;
    list.display();
    list.del(5);
    cout << "After third delete (5)" << endl;
    list.display();
    list.del(2);
    cout << "After forth delete (2)" << endl;
    list.display();
    list.del(4);
    cout << "After fifth delete (4)" << endl;
    list.display();
    list.del(1);
    cout << "After sixth delete (1)" << endl;
    list.display();
    return 0;
}