#ifndef NODE_H
#define NODE_H
#include "../com/com.h"

template<class T>
class Node 
{
    public:
    T value;
    Node* next;

    Node();
    Node(T value);
};

#endif