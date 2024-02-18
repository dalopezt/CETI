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

    int get_length()
    {
        int l = 0;
        Node<T>* aux = head;
        while (aux != NULL)
        {
            l++;
            aux = aux->next;
        }
        return l;
    }
    
    void ins_end(T value)
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

    void ins_first(T value) 
    {
        Node<T>* new_node = new Node<T>(value);
        new_node->next = head;
        head = new_node;
    };

    void ins_at_index(T value, int index)
    {
        if (index > get_length())
        {
            cout << "Value out of index" << end;
            return;
        }

        if (index == 0)
        {
            ins_first(value);
            return;
        }

        Node<T>* new_node = new Node<T>(value);
        Node<T>* aux = head;
        int l = get_length();
        for (int i = 0; i < l-1; i++)
        {
            aux = aux->next;
        }
        
        new_node->next = aux->next;
        aux->next = new_node;
    };

    void del_first_instance(T value)
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
    cin.get();
    return 0;
}