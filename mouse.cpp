#include <iostream>
#include <cstdio>
#include <gpm.h>
#include <linux/keyboard.h>
#include "fb.h"

    int xpos=0;
    int ypos=0;
    rgb red;
    
    canvas C;
int my_handler(Gpm_Event *event, void *data)
{       
    char report_string[80];

    report_string[0] = '\0';
    /*
    if(event->type & GPM_DOWN)
    {       if(event->modifiers & (1 << KG_SHIFT))
                    strcat(report_string, "Shift + ");
            if(event->modifiers & (1 << KG_CTRL))
                    strcat(report_string, "Ctrl + ");
            if(event->modifiers & (1 << KG_ALT))
                    strcat(report_string, "Left Alt + ");
            if(event->modifiers & (1 << KG_ALTGR))
                    strcat(report_string, "Right Alt + ");
            if(event->buttons & GPM_B_LEFT)
                    strcat(report_string, " Left Button click ");
            if(event->buttons & GPM_B_RIGHT)
                    strcat(report_string, " Right Button click ");
            if(event->buttons & GPM_B_MIDDLE)
                    strcat(report_string, " Middle Button click ");

            printf("%s\n", report_string);
    }
    */
    if(event->type & GPM_MOVE)
    {
        //C.fb_pset(xpos, ypos, red);
        C.fb_rectangle(xpos, ypos, xpos+20, ypos+20, 10, red );
        C.fb_rectangle(100, 100, 120, 120, 10, red );
        xpos+=event->dx*10;
        ypos+=event->dy*10;
        //std::cout<< " Mouse moved "<<std::endl;
        //printf("%s\n", report_string);
        //printf("dx:%d dy: %d x: %d y: %d X:%d\n", event->dx, event->dy, event->x, event->y, xpos );
    }
    return 0;
}

int main()
{       
    red.RED();
    C.fb_init();
    C.fb_hline(30,100,20,50,red);
    Gpm_Connect conn;
    int c;

    conn.eventMask  = ~0;
    conn.defaultMask = 0;
    conn.minMod     = 0;
    conn.maxMod     = ~0;

    if(Gpm_Open(&conn, 0) == -1)
        printf("Cannot connect to mouse server\n");
    else
        std::cout<<"Connected"<<std::endl;

    gpm_handler = my_handler;
    while((c = Gpm_Getc(stdin)) != EOF)
            printf("%c\n", c);
    Gpm_Close();
    return 0;
}

