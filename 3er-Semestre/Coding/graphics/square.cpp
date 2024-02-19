/**
 * @author: David Lopez.
 * @date: Feb 18th, 2024.
*/

#include "square.h"

Square::Square(){}

Square::Square(int x, int y, int l, int h, int f)
{
    this->x = x;
    this->y = y;
    this->l = l;
    this->h = h;
    this->f = f;

    // Fill square
    this->points = new Point*[h];
    for (int i = 0; i < h; i++) 
    {
        this->points[i] = new Point[l];
        for (int j = 0; j < l; j++)
        {
            points[i][j] = Point(x+j, y+i, '*');
        }
    }

    // Remove if not fill
    if (!f && h > 2 && l > 2) 
    {
        for (int i = 1; i < h-1; i++) 
        {
            for (int j = 1; j < l-1; j++)
            {
                points[i][j].setS(' ');
            }
        }
    }
}
int Square::getX() { return this->x; }
int Square::getY() { return this->y; }
int Square::getL() { return this->l; }
int Square::getH() { return this->h; }
int Square::getF() { return this->f; }
Point Square::getPoint(int x, int y) { return this->points[y][x]; }
Point Square::getLastPoint() { return this->points[h-1][l-1]; }
void Square::setX(int x) { this->x = x; }
void Square::setY(int y) { this->y = y; }
void Square::setL(int l) { this->l = l; }
void Square::setH(int h) { this->h = h; }
void Square::setF(int f) { this->f = f; }

void Square::display() 
{
    int x_cursor = 0;
    // Vertical offset
    int y_cursor = 0;
    while (y_cursor < getPoint(0, 0).getY()) 
    {
        std::cout << "\n";
        y_cursor++;
    }
    
    for (int i = 0; i < h; i++) {
        // Horizontal offset
        x_cursor = 0;
        while (x_cursor < getPoint(l-1, h-1).getX())
        {
            std::cout << " ";
            x_cursor++;
        }

        for (int j = 0; j < l; j++)
        {
            this->points[i][j].display();
        }

        // Next row
        std::cout << "\n";
    }
}

void Square::mov(int delta_x, int delta_y) 
{
    x += delta_x;
    y += delta_y;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < l; j++) 
        {
            points[i][j].movX(delta_x);
            points[i][j].movY(delta_y);
        }
    }
}