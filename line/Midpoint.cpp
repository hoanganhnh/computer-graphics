#include <iostream>
#include <graphics.h>

using namespace std;

void mid_line(int x1, int y1, int x2, int y2, int c) {
    int x, y, dx, dy, p;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    p = dy - dx/2;

    for (x = x1; x <= x2; x++) {
        cout << x << ", " << y << endl;  
        putpixel(x, y, c);

        if (p <= 0) {
            p += dy;
        } else {
            y += 1;
            p += dy - dx;
        }
    }
}



int main(int argc, char const *argv[]) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    mid_line(2, 5, 10, 9, WHITE);
    getch();
    closegraph();

    return 0;
}
