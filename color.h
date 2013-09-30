#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>

class rgb{
    public:
        rgb():m_red(0), m_green(0), m_blue(0){}
        rgb(char r, char g, char b):m_red(r), m_green(g), m_blue(b){}
        char red(){return m_red;}
        char green(){return m_green;}
        char blue(){return m_blue;}
        void red(char r){m_red=r;}
        void green(char g){m_green=g;}
        void blue(char b){m_blue=b;}
        void apply(char r, char g, char b);
        std::string toString();
        void RED();
        void BLUE();
        void GREEN();
        void MAGENTA();     //255,0,255
        void YELLOWGREEN();//154,205,50
        void LIGHTYELLOW();//255,255,224
        void YELLOW();      //255,255,0
        void PINK();        //255,181,197
        void VIOLET();      //238,130,238
        void ALICEBLUE();   //240,248,255
        void DIMGRAY();     //105,105,105
        void ORANGE();      //255,165,0
        void BROWN();       //165,42,42
        void WHEAT();       //245,222,179

    private:
        char m_red;
        char m_green;
        char m_blue;
};
#endif
