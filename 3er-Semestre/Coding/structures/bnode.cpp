/**
 * @author: David Lopez.
 * @date: Feb 22nd, 2024.
*/

#include "bnode.h"

/**
 * @details: Creates empty node
*/
template <class T>
BNode<T>::BNode()
{
    this->left = nullptr;
    this->right = nullptr;
}

/**
 * @details: Creates valued node.
*/
template <class T>
BNode<T>::BNode(T value)
{
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

// Explicit instantiation for int
template class BNode<int>;