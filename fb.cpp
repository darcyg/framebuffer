#include "fb.h"

canvas::canvas(){
    screensize=0;
    location=0;
    fbp=nullptr;
    foreground.apply(255,255,255);
    background.apply(0,0,0);
}

void canvas::fb_init(){
    
    /* open the file for reading and writing */
    fbfd = open("/dev/fb0",O_RDWR);
    if(!fbfd) {
        std::cout<<"Error: cannot open framebuffer device.\n";
        exit(1);
    }
 
    /* get the fixed screen information */
    if(ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo)) {
        std::cout<<"Error reading fixed information.\n";
        exit(2);
    }
 
    /* get variable screen information */
    if(ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
        std::cout<<"Error reading variable information.\n";
        exit(3);
    }
 
    /* figure out the size of the screen in bytes */
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
 
    /* map the device to memory */
    fbp = (char*)mmap(0,screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
 
    if((long)fbp == -1) {
        std::cout<<"Error: failed to map framebuffer device to memory.\n";
        exit(4);
    }
}

void canvas::fb_close(){
    close(fbfd);
}

void canvas::canvas::fb_paint(){
    munmap(fbp, screensize);
}

void canvas::fb_pset(int x, int y, rgb c)
{
    if(x>=vinfo.xres || y>=vinfo.yres)
        return;

    location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
               (y+vinfo.yoffset) * finfo.line_length;

    if ( vinfo.bits_per_pixel == 32 ) 
    {
        *(fbp + location) = c.blue();        
        *(fbp + location + 1) = c.green(); 
        *(fbp + location + 2) = c.red(); 
        *(fbp + location + 3) = 0;      // No transparency
    } 
    else  
    { //assume 16bpp
        int b = 10;
        int g = (x-100)/6;     // A little green
        int r = 31-(y-100)/16;    // A lot of red
        unsigned short int t = r<<11 | g << 5 | b;
        *((unsigned short int*)(fbp + location)) = t;
    }
}

void canvas::fb_reset()
{
    rgb black;
    for(int x=0; x<vinfo.xres; ++x)
    {
        for(int y=0; y < vinfo.yres; ++y)
        {
            fb_pset(x, y, black);
        }
    }
}
void canvas::fb_hline(int x1, int y1, int t, int l, rgb c)
{
    for(int y=y1; y<y1+t; ++y)
    {
        for(int x=x1; x<x1+l; ++x)
        {
            fb_pset(x,y, c);
        }
    }
}

void canvas::fb_vline(int x1, int y1, int t, int l, rgb c)
{
    for(int y=y1; y<y1+l; ++y)
    {
        for(int x=x1; x<x1+t; ++x)
        {
            fb_pset(x,y, c);
        }
    }
}
void canvas::fb_rectangle(int x0, int y0, int x1, int y1, int t, rgb c)
{
    fb_hline(x0, y0, t, x1-x0, c);
    fb_hline(x0, y1-t+1, t, x1-x0, c);
    fb_vline(x0, y0, t, y1-y0+1, c);
    fb_vline(x1-t, y0, t, y1-y0+1, c);
}

void canvas::fb_circle(double r, double xi, double yi, rgb c)
{
    double x, y;
    for(double i=0; i<360; ++i)
    {
        x=xi + r*cos(i);
        y=yi + r*sin(i);
        fb_pset ((int)x, (int)y, c);
    }
}

void canvas::fb_putchar(char c)
{
    rgb red(255, 0, 0);
    rgb black(0,0,0);
    std::string s;
    character ch;
    switch (c)
    {
        case 'A': s = ch.A; break;
        case 'B': s = ch.B; break;
        case 'C': s = ch.C; break;
        case 'D': s = ch.D; break;
        case 'E': s = ch.E; break;
        case 'F': s = ch.F; break;
        case 'G': s = ch.G; break;
        case 'H': s = ch.H; break;
        case 'I': s = ch.I; break;
        case 'J': s = ch.J; break;
        case 'K': s = ch.K; break;
        case 'L': s = ch.L; break;
        case 'M': s = ch.M; break;
        case 'N': s = ch.N; break;
        case 'O': s = ch.O; break;
        case 'P': s = ch.P; break;
        case 'Q': s = ch.Q; break;
        case 'R': s = ch.R; break;
        case 'S': s = ch.S; break;
        case 'T': s = ch.T; break;
        case 'U': s = ch.U; break;
        case 'V': s = ch.V; break;
        case 'W': s = ch.W; break;
        case 'X': s = ch.X; break;
        case 'Y': s = ch.Y; break;
        case 'Z': s = ch.Z; break;
        case '1': s = ch.ONE; break;
        case '2': s = ch.TWO; break;
        case '3': s = ch.THREE; break;
        case '4': s = ch.FOUR; break;
        case '5': s = ch.FIVE; break;
        case '6': s = ch.SIX; break;
        case '7': s = ch.SEVEN; break;
        case '8': s = ch.EIGHT; break;
        case '9': s = ch.NINE; break;
        case '0': s = ch.ZERO; break;
        case '-': s = ch.MINUS; break;
        case '+': s = ch.PLUS; break;
        case ' ': s = ch.blank; break;
    }
    rgb t;
    t.GREEN();
    int k=0;
    for(int y=0; y<10; ++y)
    {
        for( int x=0; x<10; ++x)
        {
            if(s[k++]=='1')
                fb_pset(Px+x, Py+y, foreground);
            else
            {
                fb_pset(Px+x, Py+y, background);
            }
        }
    }
    Px+=10;
    
}
void canvas::fb_printf(std::string c)
{
    for(int i=0; i< c.length(); ++i)
    {
        fb_putchar(c[i]);
    }
}
