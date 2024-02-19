/**
 * @author: David Lopez.
 * @date: Feb 18th, 2024.
*/

#ifndef SQUARE_H
#define SQUARE_H
#include "point.h"

class Square
{
    private:
    Point** points;
    int x;
    int y;
    int l;
    int h;
    int f;

    public:
    Square();
    Square(int x, int y, int l, int h, int f);
    int getX();
    int getY();
    int getL();
    int getH();
    int getF();
    Point getPoint(int x, int y);
    Point getLastPoint();
    void setX(int x);
    void setY(int y);
    void setL(int l);
    void setH(int h);
    void setF(int f);
    void display();
    void mov(int delta_x, int delta_y);
};

#endif