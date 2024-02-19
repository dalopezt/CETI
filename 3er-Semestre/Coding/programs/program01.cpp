/**
 * @author: David Lopez.
 * @date: Feb 18th, 2024.
*/

#include "program01.h"

Program01::Program01()
{
    this->_desc = "Animate a square over the canvas. Uses threads.";
}

int Program01::readPositiveInt()
{
    int i;
    std::cin.clear();
    std::cin >> i;
    if (i <= 0)
    {
        std::cout << "Value must be positive. Try again: ";
        return this->readPositiveInt();
    }
    return i;
}

int Program01::readBool()
{
    int i;
    std::cin.clear();
    std::cin >> i;
    if (i != 0 && i != 1)
    {
        std::cout << "Value must be 1 or 0. Try again: ";
        return this->readBool();
    }
    return i;
}

double Program01::stressorComputePi(int iterations)
{
    double pi = 0.0;
    for (int i = 0; i < iterations; ++i)
    {
        double term = 4.0/(2*i + 1);
        if (i%2 == 0)
        {
            pi += term;
        }
        else
        {
            pi -= term;
        }
    }
    return pi;
}

void Program01::animate()
{
    system("cls");
    s.display();
    switch(direction)
    {
        case 0:
            s.mov(1, 0);
            if (s.getLastPoint().getX() == this->MAX_X) 
            {
                this->direction = 1;
                return;
            }
            break;
        case 1:
            s.mov(0, 1);
            if (s.getLastPoint().getY() == this->MAX_Y) 
            {
                this->direction = 2;
                return;
            }
            break;
        case 2:
            s.mov(-1, 0);
            if (s.getLastPoint().getX() == 0) 
            {
                this->direction = 3;
                return;
            }
            break;
        case 3:
            s.mov(0, -1);
            if (s.getLastPoint().getY() == 0) 
            {
                this->direction = 0;
                return;
            }
            break;
        default:
            break;
    }
}

void Program01::execute()
{
    // Setting up the square
    int x, y, l, h, f, time;
    std::cout << "Set initial x coord (0-10): ";
    x = this->readPositiveInt();
    std::cout << "Set initial y coord (0-10): ";
    y = this->readPositiveInt();
    std::cout << "Set length (1-7): ";
    l = this->readPositiveInt();
    std::cout << "Set height (1-7): ";
    h =  this->readPositiveInt();
    std::cout << "Set if filled (1 yes, 0 no): ";
    f = this->readBool();
    std::cout << "Set timeout (seconds): ";
    time = this->readPositiveInt();
    s = Square(x, y, l, h, f);

    std::thread testThread([&]() {
        while (this->play)
        {
            this->result = this->stressorComputePi(STRESSOR_ITERATIONS);
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    });

    std::thread animationThread([&]() {
        while(this->play)
        {
            this->animate();
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
    });

    // Sleeping main thread for 10 seconds
    std::this_thread::sleep_for(std::chrono::seconds(time));
    this->play = 0; // This finishes testThread and animationThread
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    system("cls");
    std::cout << "Animation finished after " << time << " seconds\n";
    std::cout << "[Stressor] Value of Pi: " << std::setprecision(15) << this->result << "\n";

    // Join thread
    testThread.join();
    animationThread.join();

    std::cout << "Ending Program 01 execution. Going back to main menu.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    system("cls");
    this->play = 1; // Get everything ready for future executions
    this->direction = 0;
}