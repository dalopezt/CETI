/**
 * @author: David Lopez.
 * @date: Feb 18th, 2024.
*/

#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point
{
    private:
    int x;
    int y;
    char s;
    
    public:
    Point();
    Point(int x, int y, char s);
    int getX();
    int getY();
    char getS();
    void setX(int x);
    void setY(int y);
    void setS(int s);
    void movX(int delta);
    void movY(int delta);
    void display();
};

#endif