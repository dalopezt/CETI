/**
 * @author: David Lopez.
 * @date: Feb 22nd, 2024.
*/

#include "btree.h"

/**
 * @details: Builds empty Binary Tree
*/
template <class T>
BTree<T>::BTree()
{
    _root = nullptr;
}

/**
 * @details: Builds Binary Tree from List<T>
*/
template <class T>
BTree<T>::BTree(List<T> l)
{
    insBNodeList(l);
}

/**
 * @retval: 0 => Success.
 * 
 * @details: Inserts a List<T> into the given binary tree instance.
*/
template <class T>
int BTree<T>::insBNodeList(List<T> l)
{
    Node<T>* aux = l.getNodeAtIndex(0);
    while (aux != nullptr)
    {
        insBNode(aux->value);
        aux = aux->next;
    }
    return 0;
}

/**
 * @retval: 0 => Success.
 * 
 * @details: Inserts a node at the needed position of the binary tree.
*/
template <class T>
int BTree<T>::insBNode(T value)
{
    // First node (root)
    if (_root == nullptr)
    {
        BNode<T>* new_node = new BNode<T>(value);
        _root = new_node;
        return 0;
    }
    else
    {
        return this->insBNodeWithRef(value, _root);
    }
}

/**
 * @retval: 0 => Success.
 * 
 * @details: Inserts a node at the needed position of a binary tree with a given reference.
*/
template <class T>
int BTree<T>::insBNodeWithRef(T value, BNode<T>* ref)
{
    // Lower or equal than ref -> search left
    if (value <= ref->value)
    {
        // Available spot
        if (ref->left == nullptr)
        {
            BNode<T>* new_node = new BNode<T>(value);
            ref->left = new_node;
            return 0;
        }
        // Unavaibale spot
        else
        {
            return insBNodeWithRef(value, ref->left);
        }
    }

    // Greater than ref -> search right
    else 
    {
        // Available spot
        if (ref->right == nullptr)
        {
            BNode<T>* new_node = new BNode<T>(value);
            ref->right = new_node;
            return 0;
        }
        // Unavailable spot
        else
        {
            return insBNodeWithRef(value, ref->right);
        }
    }
}

/**
 * @retval: List<T> => Current pre order of the binary tree.
 * 
 * @details: Retrives the pre order of the given binary tree and return it as List<T>
*/
template <class T>
List<T> BTree<T>::getPreOrder()
{
    // Create list
    List<T>* list = new List<T>();
    getPreOrderWithRef(list, _root);
    return *list;
}

/**
 * @param: List<T>* list => Target list.
 * @param: BNode<T>* ref => Current studied node.
 * 
 * @details: Retrives the pre order of the given binary tree from a given reference.
*/
template <class T>
void BTree<T>::getPreOrderWithRef(List<T>* list, BNode<T>* ref)
{
    // If ref == null -> binary tree is empty
    if (ref == nullptr)
    {
        return;
    }

    // Go left
    if (ref->left != nullptr)
    {
        getPreOrderWithRef(list, ref->left);
    }

    // Insert node
    Node<T>* new_node = new Node<T>(ref->value);
    list->insBack(new_node->value);

    // Go right
    if (ref->right != nullptr)
    {
        getPreOrderWithRef(list, ref->right);
    }
}

// Explicit instantiation for int and string
template class BTree<int>;