/**
 * @author: David Lopez.
 * @date: Feb 18th, 2024.
*/

#ifndef PROGRAM_01_H
#define PROGRAM_01_H

#include "program.h"
#include "../graphics/square.h"
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <iomanip>

// using namespace std;
// using namespace std::this_thread;
// using namespace std::chrono;

class Program01 : public Program
{
    protected:
    int readPositiveInt();
    int readBool();
    double stressorComputePi(int iterations);
    int MAX_X = 20;
    int MAX_Y = 20;
    int STRESSOR_ITERATIONS = 2000000;
    int play = 1;
    double result;
    Square s;
    int direction = 0;
    void animate();

    public:
    Program01(); 
    void execute();
};

#endif