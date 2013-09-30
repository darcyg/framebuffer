#include "Point.h"

using namespace std;

Point::Point(int in_x, int in_y){
    setX(in_x);
    setY(in_y);

}

void Point::setX(int in_x){m_x = in_x;}
void Point::setY(int in_y){m_y = in_y;}
int Point::getX(){ return m_x; }
int Point::getY(){ return m_y; }
void Point::moveX(int in_x){ m_x+=in_x; }
void Point::moveY(int in_y){ m_y+=in_y; }
int Point::distanceFrom(Point& P){
    int dx = P.getX() - getX();
    int dy = P.getY() - getY();
    return sqrt( dx*dx + dy*dy);
}

string Point::toString(){
    string ret= string("(") + 
        to_string(getX()) + ", " + 
        to_string(getY()) + ", " + 
        m_color.toString() + ")";
    return ret;
}
