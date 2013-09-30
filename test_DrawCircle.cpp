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
    rgb rouge;
    rouge.RED();
    C.fb_circle(60, 200,200,rouge);
    C.fb_circle(40, 200,200,yellow);
    C.fb_circle(20, 200,200,blue);
    C.fb_close();
    return 0;
}
