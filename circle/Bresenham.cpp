#include <graphics.h>
#include <iostream>

using namespace std;

void pc(int xc,int yc,int x, int y, int color) { 
    putpixel(xc + x, yc + y, color);
    putpixel(xc - x, yc - y, color);
    putpixel(xc -y, yc +x, color);
    putpixel(xc +y, yc -x, color);
}

void Bresenham_Circle(int xc, int yc, int Radius, int color){
    int x, y, p;
    x = 0;
    y = Radius;
    p = 3 - 2 * Radius;
    // pc(xc,yc, Radius,0, color);
    while (x < y){
        // cout << x << ", " << y << endl;
        putpixel(xc + x, yc + y, color);
        if (p < 0)
            p += 4 * x + 6;
        else {
            p += 4 * (x-y) + 10;
            y--;
        }
        x++;
        // pc(xc,yc, x,y, color);
        // pc(xc,yc, y,x, color);
    }
    // pc(xc,yc, y,y, color);
}
int main(){
    int gr_drive = DETECT, gr_mode;
    initgraph(&gr_drive, &gr_mode, (char*)"");
    // Bresenham_Circle(getmaxx() / 2, getmaxy() / 2, 150, 4);
    Bresenham_Circle(0, 0, 10, 4);
    getch();
    closegraph();
    return 0;
}

