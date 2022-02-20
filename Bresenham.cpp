#include <iostream>
#include <graphics.h>

using namespace std;

void bre_line(int x1, int y1, int x2, int y2, int c) {
    int x, y, dx, dy, p;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    p = 2*dy - dx;

    for (x = x1; x <= x2; x++) {
        putpixel(x, y, c);

        if (p <= 0) {
            p += 2*dy;
        } else {
            p += 2*dy - 2*dx;
            y += 1;
        }
    }
}



int main(int argc, char const *argv[]) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    bre_line(2, 5, 10, 9, WHITE);
    bre_line(12, 20, 22, 27, WHITE);
    getch();
    closegraph();

    return 0;
}
