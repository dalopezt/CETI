/**
 * @author: David Lopez.
 * @date: Feb 18th, 2024.
*/

#include "point.h"

Point::Point(){}
Point::Point(int x, int y, char s) 
{
    this->x = x;
    this->y = y;
    this->s = s;
}
int Point::getX() { return this->x; }
int Point::getY() { return this->y; }
char Point::getS() { return this->s; }
void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }
void Point::setS(int s) { this->s = s; }
void Point::movX(int delta) { this->x += delta; }
void Point::movY(int delta) { this->y += delta; }
void Point::display() { std::cout << getS(); }