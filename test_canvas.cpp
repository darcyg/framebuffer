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
    C.fb_hline(200,280,10,100,violet);
    C.fb_hline(200,300,10,100,blue);
    C.fb_hline(200,320,10,100,aliceblue);
    C.fb_hline(200,340,10,100,orange);
    C.fb_hline(200,360,10,100,green);
    C.fb_hline(200,380,10,100,yellow);
    rgb rouge;
    rouge.RED();
    C.fb_circle(60, 200,200,rouge);
    C.fb_putchar('A');
    C.background.apply(234,123,43);
    C.Px=40; 
    C.fb_putchar('B');
    C.background.red(0);
    C.fb_putchar('C');
    C.Py=50;
    C.fb_putchar('D');
    C.fb_printf("ABCD"); 
    C.Py=60;
    C.background.RED(); 
    C.fb_printf("MARIO ST GELAIS"); 
    C.Py=70;
    C.Px=40; 
    C.fb_printf("1234567890-+"); 
    C.fb_close();
    C.fb_rectangle(100,200,200,300,1,blue);
    return 0;
}
