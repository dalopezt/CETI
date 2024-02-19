/**
 * @author: David Lopez.
 * @date: Feb 18th, 2024.
*/

#include "list.h"

/**
 * @details: Builds empty list.
*/
template <class T>
List<T>::List()
{
    _head = nullptr;
} 

/**
 * @details: Builds list from array.
*/
template <class T>
List<T>::List(T* list, int len)
{
    _head = nullptr;
    for (int i = 0; i < len; ++i)
    {
        insBack(list[i]);
    }
}

/**
 * @retval: int => current list length.
 * 
 * @details: Calculates the length of the list. 
*/
template <class T>
int List<T>::getLength()
{
    int l = 0;
    Node<T>* aux = _head;
    while (aux != nullptr)
    {
        ++l;
        aux = aux->next;
    }
    return l;
}

/**
 * @retval: 0 => Out of index.
 * @retval: Node<T> => Node at given index.
 * 
 * @details: Retrives the node pointer at the given index. 
*/
template <class T>
Node<T>* List<T>::getNodeAtIndex(int index)
{
    if (index < 0 || index >= getLength())
    {
        return 0;
    }

    Node<T>* aux = _head;
    for (int i = 0; i < index; ++i)
    {
        aux = aux->next;
    }
    return aux;
}

/**
 * @retval: 0 => Success.
 * 
 * @details: Inserts a node at the back of the list.
*/
template <class T>
int List<T>::insBack(T value)
{
    Node<T>* new_node = new Node<T>(value);
    if (_head == nullptr)
    {
        _head = new_node;
        return 0;
    }

    Node<T>* aux = _head;
    while (aux->next != nullptr)
    {
        aux = aux->next;
    }
    aux->next = new_node;

    return 0;
}

/**
 * @retval: 0 => Success.
 * 
 * @details: Inserts a node at the front of the list.
*/
template <class T>
int List<T>::insFront(T value)
{
    Node<T>* new_node = new Node<T>(value);
    new_node->next = _head;
    _head = new_node;
    return 0;
}

/**
 * @retval: 0 => Success.
 * @retval: 1 => Index out of range. 
 * 
 * @details: Inserts a node at a given index.
*/
template <class T>
int List<T>::insAtIndex(T value, int index)
{
    int l = getLength();
    if (index > l || index < 0)
    {
        return 1;
    }

    if (index == 0)
    {
        insFront(value);
        return 0;
    }

    Node<T>* new_node = new Node<T>(value);
    Node<T>* aux = _head;
    for (int i = 0; i < l-1; ++i)
    {
        aux = aux->next;
    }
    
    new_node->next = aux->next;
    aux->next = new_node;
    return 0;
}

/**
 * @retval: 0 => Success
 * @retval: 1 => Empty list
 * @retval: 2 => Didn't find instance
 * 
 * @details: Deletes the first instance of a certain value.
*/
template <class T>
int List<T>::delFirstInstance(T value)
{
    // Empty list
    if (_head == nullptr)
    {
        return 1;
    }
    
    Node<T>* aux = _head;
    // Check if header is the match
    if (aux->value == value)
    {
        _head = aux->next;
        delete aux;
        return 0;
    }

    // Move until aux->next has the value
    while (aux->next->value != value && aux->next != nullptr)
    {
        aux = aux->next;
    }

    // If didn't match, abort
    if (aux->next == nullptr)
    {
        return 2;
    }

    // Otherwise
    Node<T>* temp = aux->next;
    aux->next = temp->next;
    delete temp;
    return 0;
}

/**
 * @retval: true => The value is on the list.
 * @retval: false => The value is not on the list.
 * 
 * @details: Checks if a given value appears on the list.
*/
template <class T>
bool List<T>::contains(T value)
{
    Node<T>* aux = _head;
    while (aux != nullptr)
    {
        if (aux->value == value)
        {
            return true;
        }
        aux = aux->next;
    }
    return false;
}

// Explicit instantiation for int and string
template class List<int>;
template class List<option>;