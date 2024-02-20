/**
 * @author: David Lopez.
 * @date: Feb 18th, 2024.
*/

#include "menu.h"

Menu::Menu(){}

Menu::Menu(std::string title, int len, option options[])
{
    _title = title;
    _len = len;
    _options = List<option>(options, len);
}

void Menu::loadMenu(std::string title, int len, option options[])
{
    _title = title;
    _len = len;
    _options = List<option>(options, len);
}

std::string Menu::optionsToString()
{
    std::string output = _title;
    output += "\n"; 
    for (int i = 0; i < _len; ++i)
    {
        output += "[";
        output += std::to_string(i);
        output += "] ";
        output += _options.getNodeAtIndex(i)->value.desc;
        output += "\n";
    }
    output += "[";
    output += std::to_string(_len);
    output += "] Exit\n";
    return output;
}

int Menu::readOption()
{
    int option;
    std::cout << optionsToString();
    std::cin.clear();
    std::cin >> option;
    if (option < 0 || option > _len)
    {
        std::cout << "Invalid input, try again.\n";
        std::cin.get();
        return readOption();
    }
    return option;
}

int Menu::executeOption(int option)
{
    if (option > _len || option < 0)
    {
        std::cout << "Option out of range.\n";
        return 1;
    }

    if (option < _len)
    {
        // Execute function
        system("cls");
        _options.getNodeAtIndex(option)->value.proc();
        return 1;
    }

    std::cout << "Exiting menu.\n";
    return 0;
}

void Menu::execute()
{
    while (executeOption(readOption()));
}