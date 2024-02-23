/**
 * @author: Dvaid Lopez.
 * @date: Feb 22nd, 2024.
*/

#ifndef BNODE_H
#define BNODE_H
#include "../com/com.h"

template<class T>
class BNode
{
    public:
    T value;
    BNode* left;
    BNode* right;

    BNode();
    BNode(T value);
};

#endif