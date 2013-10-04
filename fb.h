#ifndef FB_H
#define FB_H

#include <unistd.h>
#include <fcntl.h>            /* for fcntl */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>     /* for mmap */
#include <sys/ioctl.h>
#include <linux/fb.h>

#include <math.h> 
#include <string>
#include <iostream>
#include "Point.h"
#include "characters.h"

class canvas{
    public:
        canvas();
        ~canvas(){};
        void fb_init();
        void fb_close();
        void fb_paint();
        void fb_vline(int x1, int y1, int t, int l, rgb c);
        void fb_hline(int x1, int y1, int t, int l, rgb c);
        void fb_rectangle(int x0, int y0, int x1, int y1, int t, rgb c);
        void fb_circle(double r, double xi, double yi, rgb c);
        void fb_pset(int x, int y, rgb c);
        void fb_pset(Point p, rgb c){fb_pset(p.getX(), p.getY(), c);}
        void fb_reset();
        void fb_putchar(char c);
        void fb_printf(std::string c);

        rgb foreground;
        rgb background;
        int Px{0};
        int Py{0};
        char* fbp;        /* pointer to framebuffer */
        int location;     /* iterate to location */
        long int screensize;
        int fbfd;  //Frame buffer file descriptor
        struct fb_var_screeninfo vinfo;
        struct fb_fix_screeninfo finfo;

};

#endif
