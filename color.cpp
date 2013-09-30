#include "color.h"

std::string rgb::toString()
{
    std::string s=std::string("(") + 
        std::to_string((int)m_red) + ", " + 
        std::to_string(m_green) + ", " + 
        std::to_string(m_blue) + ")";
    return s;
}

void rgb::apply(char r, char g, char b)
{
    m_red=r;
    m_green=g;
    m_blue=b;
}

void rgb::RED()
{
    m_red=254;
    m_green=0;
    m_blue=0;
}
void rgb::GREEN()
{
    m_red=0;
    m_green=255;
    m_blue=0;
}
void rgb::BLUE()
{
    m_red=0;
    m_green=0;
    m_blue=255;
}
void rgb::MAGENTA()
{
    m_red=255;
    m_green=0;
    m_blue=255;
}
void rgb::YELLOWGREEN()
{
    m_red   =154;
    m_green =205;
    m_blue  =50;
}
void rgb::LIGHTYELLOW()
{
    m_red=255;
    m_green=255;
    m_blue=224;
}
void rgb::YELLOW()
{
    m_red=255;
    m_green=255;
    m_blue=0;
}
void rgb::PINK()
{
    m_red=255;
    m_green=181;
    m_blue=197;
}
void rgb::VIOLET()
{
    m_red=238;
    m_green=130;
    m_blue=238;
}
void rgb::ALICEBLUE()
{
    m_red=240;
    m_green=248;
    m_blue=255;
}
void rgb::DIMGRAY()
{
    m_red=105;
    m_green=105;
    m_blue=105;
}
void rgb::ORANGE()
{
    m_red=255;
    m_green=165;
    m_blue=0;
}
void rgb::BROWN()
{
    m_red=165;
    m_green=42;
    m_blue=43;
}
void rgb::WHEAT()
{
    m_red=245;
    m_green=222;
    m_blue=179;
}
