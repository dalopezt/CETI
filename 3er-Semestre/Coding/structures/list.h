/**
 * @author: David Lopez
 * @date: Feb 18th, 2024.
*/

#ifndef LIST_H
#define LIST_H
#include "node.h"

template<class T>
class List
{
    private:
    Node<T>* _head;

    public:
    List();
    List(T* list, int len);
    int getLength();
    Node<T>* getNodeAtIndex(int index);
    int insBack(T value);
    int insFront(T value);
    int insAtIndex(T value, int index);
    int delFirstInstance(T value); 
    bool contains(T value);
    int clear();

    List<T> operator+ (List<T> list);
    List<T> operator+= (List<T> list);
    List<T> operator--();
};

#endif