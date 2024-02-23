/**
 * @author: David Lopez.
 * @date: Feb 22nd, 2024.
*/
#include "program03.h"

Program03::Program03()
{
    // Capture methods in actual std::function form to build the menu options
    std::function<void()> f1 = [this](){
        this->insNode();
    };
    std::function<void()> f2 = [this](){
        this->insNodeList();
    };
    std::function<void()> f3 = [this](){
        this->printPreOrder();
    };

    // Build options
    option opt1 = {"Insert node", f1};
    option opt2 = {"Insert node list", f2};
    option opt3 = {"Print Pre Order Binary List", f3};
    option options[] = { opt1, opt2, opt3 };

    this->_desc = "Creates a binary tree of integers and operates on it.";
    this->_menu.loadMenu("Program 03 menu. Binary Tree", 3, options);
}

List<int> Program03::readVirtualList()
{
    List<int> virtualList;
    int n, temp;

    system("cls");
    std::cout << "Capturing virtual list\n";
    std::cout << "Elements: ";
    std::cin.clear();
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Element " << i << ": ";
        std::cin.clear();
        std::cin >> temp;
        virtualList.insBack(temp);
    }
    return virtualList;
}

void Program03::insNode()
{
    int new_value;
    std::cout << "Insert new value: ";
    std::cin.clear();
    std::cin >> new_value;
    if (_btree.insBNode(new_value) == 0)
    {
        std::cout << "Node inserted succesfully. Going back to menu.\n\n";
    }
    else
    {
        std::cout << "Something went wrong while inserting node.\n\n";
    }
}

void Program03::printPreOrder()
{
    system("cls");
    List<int> preOrderList = _btree.getPreOrder();
    std::cout << "Printing pre-ordered list:\n";
    printGivenList(preOrderList);
}

void Program03::insNodeList()
{
    List<int> virtualList = readVirtualList();
    std::cout << "\nVirtual list:\n";
    printGivenList(virtualList);
    _btree.insBNodeList(virtualList);
    std::cout << "Virtual list successfully added to binary tree\n";
    std::cin.clear();
    std::cin.get();
}

void Program03::printGivenList(List<int> list)
{
    int l = list.getLength(); 
    if (l == 0)
    {
        std::cout << "List is empty\n\n";
        return;
    }

    std::cout << "Printing " << l << " node(s).\n";
    Node<int>* aux = list.getNodeAtIndex(0);
    while (aux != nullptr)
    {
        std::cout << aux->value << "\n";
        aux = aux->next;
    }
    std::cout << "\n";
}

void Program03::execute()
{
    _menu.execute();
    std::cout << "Exiting program. Bye.\n";
    std::cin.clear();
    std::cin.get();
    system("cls");
}