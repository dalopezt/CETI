/**
 * @author: David Lopez.
 * @date: Feb 19th, 2024.
*/

#ifndef PROGRAM_02_H
#define PROGRAM_02_H

#include "program.h"
#include "../structures/list.h"
#include "../menu/menu.h"

class Program02 : public Program
{
    protected:
    List<int> _list;
    Menu _menu;
    void insBack();
    void insFront();
    void insAtIndex();
    void delFirstInstance();
    void printList();
    void clearList();
    void addVirtualList();
    void addToVirtualList();
    void delFirstElement();

    void printGivenList(List<int> l);
    List<int> readVirtualList();

    public:
    Program02();
    void execute();
};

#endif