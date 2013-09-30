#include "fb.h"

int main(void)
{
    canvas C;
    rgb blue(0, 0, 255);
    rgb green;
    green.GREEN();
    rgb violet;
    violet.MAGENTA();
    rgb yellow;
    yellow.YELLOW();
    rgb rouge;
    rouge.RED();

    C.fb_init();
    C.fb_reset();

    C.fb_putchar('A');
    C.background.apply(234,123,43);
    C.Px=40; 
    C.fb_putchar('B');
    C.background.red(0);
    C.fb_putchar('C');
    C.Py=50;
    C.fb_putchar('D');
    C.fb_printf("X - Y - Z"); 
    C.Py=60;
    C.background.RED(); 
    C.fb_printf("HELLO WORLD"); 
    C.Py=70;
    C.Px=40; 
    C.fb_printf("1234567890-+"); 
    C.fb_rectangle(100,200,200,300,1,blue);
    C.fb_close();
    return 0;
}
