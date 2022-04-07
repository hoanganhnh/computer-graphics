#include <graphics.h>
#include <conio.h>
#include <iostream>

#define ROUND(a) ((long)(a+0.5))

void plot(int xc, int yc, int x, int y, int color){
    putpixel(xc+x, yc+y, color);
    putpixel(xc-x, yc+y, color);
    putpixel(xc+x, yc-y, color);
    putpixel(xc-x, yc-y, color);
}

void Mid_ellipse(int xc, int yc, int a, int b, int color){
    long x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a * a; //a2
    b2 = b * b; // b2
    fx = 0;
    fy = 2 * a2 * y; // 2a2y
    plot(xc, yc, x,y, color);
    p = ROUND(b2-(a2*b)+(0.25*a)); // p=b2 - a2b + a2/4

    while (fx < fy) {
        x++;
        fx += 2*b2; //2b2
        if (p<0) {
            p += b2*(2*x +3); // p=p + b2 (2x +3)
        } else {
            y--;
            p+= b2*(2*x +3) + a2*(-2*y +2); // p = p + b2(2x +3) + a2 (-2y +2)
            fy -= 2*a2; // 2a2
        }
        plot(xc, yc, x, y, color);
    }
    p = ROUND(b2*(x+0.5)*(x+0.5) + a2*(y-1)*(y-1) - a2*b2);//b2(x+1/2)2+a2(y1)2 - a2b2

    while (y>0) {
        y--;
        fy -= 2*a2; // 2a2
        if (p>=0) {
            p+=a2*(3 - 2*y); //p =p + a2(3-2y)
        } else {
            x++;
            fx += 2*b2; // 2b2
            p += b2*(2*x+2) + a2*(-2*y +3); //p=p + b2(2x +2) +a2(-2y +3)
        }
        plot(xc, yc, x, y, color);
    }
}

int main() {
    int gr_drive = DETECT, gr_mode;
    initgraph(&gr_drive, &gr_mode, (char*)"");
    Mid_ellipse(getmaxx() / 2, getmaxy() / 2, 150, 80, 4);
    getch();
    closegraph();
    return 0;
}
