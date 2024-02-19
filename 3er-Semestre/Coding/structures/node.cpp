/**
 * @author: David Lopez.
 * @date: Feb 18th, 2024.
*/

#include "node.h"

template <class T>
/**
 * @details: Creates empty node.
*/
Node<T>::Node()
{
    this-> next = nullptr;
}

template <class T>
/**
 * @details: Creates valued node.
*/
Node<T>::Node(T value) 
{
    this->value = value;
    this->next = nullptr;
}

// Explicit instantiation for int
template class Node<int>;
template class Node<option>;