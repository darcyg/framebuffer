#ifndef POINT_H
#define POINT_H
#include <string>
#include <iostream>
#include <math.h>
#include "color.h"

class Point{

    public:
        Point():m_x(0), m_y(0), m_color(0, 0, 0){}
        Point(int in_x, int in_y);
        Point(int x, int y, rgb c)
            :m_x(x), m_y(y), m_color(c){}
        int getX();
        int getY();
        void setX(int in_x);
        void setY(int in_y);
        void moveX(int in_x);
        void moveY(int in_y);
        int distanceFrom(Point& P);
        rgb color(){return m_color;};

        std::string toString();

    private:
        int m_x;
        int m_y;
        rgb m_color;
};

#endif
