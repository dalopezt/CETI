/**
 * @author: David Lopez.
 * @date: Feb 22nd, 2024.
*/

#ifndef PROGRAM_03_H
#define PROGRAM_03_H

#include "program.h"
#include "../menu/menu.h"
#include "../structures/btree.h"

class Program03 : public Program
{
    protected:
    Menu _menu;
    BTree<int> _btree;
    void insNode();
    void insNodeList();
    void printPreOrder();
    void printGivenList(List<int> l);
    List<int> readVirtualList();

    public:
    Program03();
    void execute();
};

#endif