//g++ -g --std=c++11 -D_GLIBCXX_USE_NANOSLEEP -pthread -lm test_drawPoints.cpp fb.cpp Point.cpp color.cpp
#include "fb.h"
#include <chrono>
#include <thread>

int main(void)
{
    Point P;
    canvas c;
    c.fb_init();
    c.fb_reset();
    rgb yellow;
    rgb black;
    yellow.YELLOW();
    std::chrono::milliseconds dura(1);
    for (int i=0; i<400; ++i)
    {
        P.setY(i);
        for(int j=0; j<900; ++j)
        {
            P.setX(j);
            c.fb_pset(P, yellow);
            std::this_thread::sleep_for(dura);
            c.fb_pset(j-1,i,black);
        }
    }

}
