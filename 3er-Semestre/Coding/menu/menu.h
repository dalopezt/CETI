/**
 * @author: David Lopez.
 * @date: Feb 18th, 2024.
*/

#ifndef MENU_H
#define MENU_H
#include "../structures/list.h"

class Menu
{
    private:
    std::string _title;
    int _len = 0;
    List<option> _options;

    public:
    Menu();
    Menu(std::string title, int len, option options[]);
    std::string optionsToString();
    int readOption();
    int executeOption(int option);
    void execute();
    void loadMenu(std::string title, int len, option options[]);
};

#endif