/**
 * @author: Dvaid Lopez.
 * @date: Feb 19th, 2024.
*/

#include "program02.h"

Program02::Program02()
{
    // Capture methods in actual std::function form to build the menu options 
    std::function<void()> f1 = [this](){
        this->insBack();
    };
    std::function<void()> f2 = [this](){
        this->insFront();
    };
    std::function<void()> f3 = [this](){
        this->insAtIndex();
    };
    std::function<void()> f4 = [this](){
        this->delFirstInstance();
    };
    std::function<void()> f5 = [this](){
        this->printList();
    };
    std::function<void()> f6 = [this](){
        this->clearList();
    };
    std::function<void()> f7 = [this](){
        this->addVirtualList();
    };
    std::function<void()> f8 = [this](){
        this->addToVirtualList();
    };
    std::function<void()> f9 = [this](){
        this->delFirstElement();
    };

    // Build options
    option opt1 = {"Insert on the back", f1};
    option opt2 = {"Insert on the front", f2};
    option opt3 = {"Insert on given index", f3};
    option opt4 = {"Delete first instance", f4};
    option opt5 = {"Print list", f5};
    option opt6 = {"Clear list", f6};
    option opt7 = {"Add a new list to the current list (operator+=)", f7};
    option opt8 = {"Add the current list to a new list (preserves current list) (operator+)", f8};
    option opt9 = {"Delete first element of the list (operator-- prefix)", f9};
    option options[] = { opt1, opt2, opt3, opt4, opt5, opt6, opt7, opt8, opt9 };

    this->_desc = "Create a list of integers from a template list and operates on it.";
    _menu.loadMenu("Program 02 menu: List", 9, options);
}

void Program02::insBack()
{
    int new_value;
    std::cout << "Insert new value: ";
    std::cin.clear();
    std::cin >> new_value;
    if (_list.insBack(new_value) == 0)
    {
        std::cout << "Node inserted succesfully. Going back to menu.\n\n";
    }
    else
    {
        std::cout << "Something went wrong while inserting node.\n\n";
    }
}

void Program02::insFront()
{
    int new_value;
    std::cout << "Insert new value: ";
    std::cin.clear();
    std::cin >> new_value;
    if (_list.insFront(new_value) == 0)
    {
        std::cout << "Node inserted succesfully. Going back to menu.\n\n";
    }
    else
    {
        std::cout << "Something went wrong while inserting node.\n\n";
    }
}

void Program02::insAtIndex()
{
    int new_value, index;
    std::cout << "Insert new value: ";
    std::cin.clear();
    std::cin >> new_value;
    std::cout << "Insert desired index: ";
    std::cin.clear();
    std::cin >> index;
    if (_list.insAtIndex(new_value, index) == 0)
    {
        std::cout << "Node inserted succesfully. Going back to menu.\n\n";
    }
    else
    {
        std::cout << "Index out of range. Try again.\n\n";
    }
}

void Program02::delFirstInstance()
{
    int target_value;
    std::cout << "Type target value: ";
    std::cin.clear();
    std::cin >> target_value;
    if (_list.delFirstInstance(target_value) == 0)
    {
        std::cout << "Node delated succesfully. Going back to menu.\n";
    }
    else
    {
        std::cout << "Node value didn't match. Try again.\n";
    }

}

void Program02::printList()
{
    printGivenList(_list);
}

void Program02::clearList()
{
    if (_list.clear() == 0)
    {
        std::cout << "List cleared correctly.\n\n";
    }
    else
    {
        std::cout << "Something went wrong while clearing the list.\n\n";
    }
}

List<int> Program02::readVirtualList()
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

void Program02::addVirtualList()
{
    List<int> virtualList = readVirtualList();
    std::cout << "\nVirtual list:\n";
    printGivenList(virtualList);
    _list += virtualList;
    std::cout << "Virtual list successfully added to list\n";
    std::cin.clear();
    std::cin.get();
}

void Program02::addToVirtualList()
{
    List<int> virtualList = readVirtualList();
    std::cout << "\nVirtual list:\n";
    printGivenList(virtualList);
    List<int> new_list = virtualList + _list;
    std::cout << "Adding the current list to the virtual list gives the following list:\n\n";
    printGivenList(new_list);
    std::cin.clear();
    std::cin.get();
}

void Program02::delFirstElement()
{
    --_list;
    std::cout << "Operator -- successfully applied on list\n\n";
}

void Program02::printGivenList(List<int> list)
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

void Program02::execute()
{
    _menu.execute();
    std::cout << "Exiting program. Bye.\n";
    std::cin.clear();
    std::cin.get();
    system("cls");
}



