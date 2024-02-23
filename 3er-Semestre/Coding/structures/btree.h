/**
 * @author: David Lopez. 
 * @date: Feb 22nd, 2024.
*/

#ifndef BTREE_H
#define BTREE_H
#include "bnode.h"
#include "list.h"

template <class T>
class BTree
{
    protected:
    BNode<T>* _root;
    int insBNodeWithRef(T value, BNode<T>* ref);
    void getPreOrderWithRef(List<T>* l, BNode<T>* ref);

    public:
    BTree();
    BTree(List<T> l);
    int insBNode(T value);
    int insBNodeList(List<T> l);
    List<T> getPreOrder();
};

#endif