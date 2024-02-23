/**
 * @author: David Lopez.
 * @date: Feb 18th, 2024.
*/

#include "menu/menu.h"
#include "programs/program01.h"
#include "programs/program02.h"
#include "programs/program03.h"

int main()
{
    Program01 program01;
    Program02 program02;
    Program03 program03;

    // Capture methods in actual std::function form to build the menu options
    std::function<void()> p1 = [&program01]() {
        program01.execute();
    };
    std::function<void()> p2 = [&program02]() {
        program02.execute();
    };
    std::function<void()> p3 = [&program03]() {
        program03.execute();
    };

    // Build options
    option opt1 = { program01._desc, p1 };
    option opt2 = { program02._desc, p2 };
    option opt3 = { program03._desc, p3 };
    option options[] = { opt1, opt2, opt3 };

    // Create and execute menu
    Menu main_menu("Main Menu", 3, options);
    main_menu.execute();

    // Exit program
    std::cout << "Exiting program. Bye.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}