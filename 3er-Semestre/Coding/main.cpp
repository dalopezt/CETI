/**
 * @author: David Lopez.
 * @date: Feb 18th, 2024.
*/

#include "menu/menu.h"
#include "programs/program01.h"

int main()
{
    Program01 program01;
    std::function<void()> p1 = [&program01]() {
        program01.execute();
    };

    option options[] = { program01._desc, p1 };
    Menu main_menu("Main Menu", 1, options);
    main_menu.execute();
    std::cout << "Exiting program. Bye.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}