/*
@author: David Alejandro López Torres
@id: 22310432
@date: Feb 6th, 2024
*/

#define FPS 120
#define L 5
#define H 3
#define x_0 0
#define y_0 0
#define F 0

#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

class Point
{
    private:
    int x;
    int y;
    char s;
    
    public:
    Point(){}
    Point(int x, int y, char s) 
    {
        this->x = x;
        this->y = y;
        this->s = s;
    }
    int getX() { return this->x; }
    int getY() { return this->y; }
    char getS() { return this->s; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setS(int s) { this->s = s; }
    void movX(int delta) { this->x += delta; }
    void movY(int delta) { this->y += delta; }
    void display() { cout << getS(); }
};

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
    Square(int x, int y, int l, int h, int f)
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
            cout << "Not Fill" << endl;
            for (int i = 1; i < h-1; i++) 
            {
                for (int j = 1; j < l-1; j++)
                {
                    points[i][j].setS(' ');
                }
            }
        }
    }
    int getX() { return this->x; }
    int getY() { return this->y; }
    int getL() { return this->l; }
    int getH() { return this->h; }
    int getF() { return this->f; }
    Point getPoint(int x, int y) { return this->points[y][x]; }
    Point getLastPoint() { return this->points[h-1][l-1]; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setL(int l) { this->l = l; }
    void setH(int h) { this->h = h; }
    void setF(int f) { this->f = f; }

    void display() 
    {
        int x_cursor = 0;
        // Vertical offset
        int y_cursor = 0;
        while (y_cursor < getPoint(0, 0).getY()) 
        {
            cout << endl;
            y_cursor++;
        }
        
        for (int i = 0; i < h; i++) {
            // Horizontal offset
            x_cursor = 0;
            while (x_cursor < getPoint(l-1, h-1).getX())
            {
                cout << " ";
                x_cursor++;
            }

            for (int j = 0; j < l; j++)
            {
                this->points[i][j].display();
            }

            // Next row
            cout << endl;
        }
    }
    void mov(int delta_x, int delta_y) 
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

};

void animation(Square s)
{
    // Right
    while (s.getLastPoint().getX() < 20)
    {
        system("cls");
        s.display();
        sleep_for(milliseconds(3600/FPS));
        s.mov(1, 0);
    }

    // Down
    while (s.getLastPoint().getY() < 20)
    {
        system("cls");
        s.display();
        sleep_for(milliseconds(3600/FPS));
        s.mov(0, 1);
    }

    // Left
    while (s.getX() > 0)
    {
        system("cls");
        s.display();
        sleep_for(milliseconds(3600/FPS));
        s.mov(-1, 0);
    }

    // Up
    while (s.getY() > 0)
    {
        system("cls");
        s.display();
        sleep_for(milliseconds(3600/FPS));
        s.mov(0, -1);
    }
}

int main()
{
    Square s(x_0, y_0, L, H, F);
    while(true)
    {
        animation(s);
    }
    return 0;
}