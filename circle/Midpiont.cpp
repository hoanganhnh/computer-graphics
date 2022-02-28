#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

void pc(int x0,int y0,int x, int y, int color) {

  putpixel( x0 + x , y0 + y ,color);
  putpixel( x0 - x , y0 + y ,color);
  putpixel( x0 + x , y0 - y ,color);
  putpixel( x0 - x , y0 - y ,color);
  putpixel( x0 + y , y0 + x ,color);
  putpixel( x0 - y , y0 + x ,color);
  putpixel( x0 + y , y0 - x ,color);
  putpixel( x0 - y , y0 - x ,color);

}

void Bresenham_Circle(int xc, int yc, int Radius, int color){
    int x, y, p;
    x = 0;
    y = Radius;
    p = 3 - 2 * Radius;
    while (x < y){
        // cout << x << ", " << y << endl;
        pc(xc , yc, x, y, color);
        if (p < 0)
            p += 4*x + 6;
        else {
            p += 4*(x-y) + 10;
            y--;
        }
        x++;
    }
}
int main(){
    int gr_drive = DETECT, gr_mode;
    initgraph(&gr_drive, &gr_mode, (char*)"");
    Bresenham_Circle(getmaxx() / 2, getmaxy() / 2, 150, WHITE);
    getch();
    closegraph();
    return 0;
}

