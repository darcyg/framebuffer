#include "fb.h"

int main(void)
{
    canvas C;
    rgb blue(0, 0, 255);
    rgb green;
    green.GREEN();
    rgb violet;
    violet.MAGENTA();
    rgb aliceblue;
    aliceblue.ALICEBLUE();
    rgb orange;
    orange.ORANGE();
    rgb yellow;
    yellow.YELLOW();

    C.fb_init();
    C.fb_reset();
    C.fb_rectangle(100,20,200,30,1,blue);
    C.fb_rectangle(205,20,305,30,5,green);
    C.fb_rectangle(100,35,200,45,5,orange);
    C.fb_rectangle(400,100,600,400,1,yellow);
    return 0;
}
