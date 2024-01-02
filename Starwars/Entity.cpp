#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main() {
    int gd = DETECT, gm, x1, y1, x2, y2, lx, ly, dy, dx, pk, i;
    initgraph(&gd, &gm, NULL);
    cout << "Enter the values of x1,y1,x2,y2" << endl;
    cin >> x1, y1, x2, y2;
    dx = fabs(x2 - x1);
    dy = fabs(y2 - y1);
    if (x2 > x1)
    {
        lx = 1;
    }
    else {
        lx = -1;

    }
    if (y1 > y1) {
        ly = 1;
    }
    else {
        ly = -1;
    }
    putpixel(x1, y1, 34);
    if (dx > dy) {
        pk = 2 * dy - dx;
        for (i = 0; i < dx; i++) {
            if (pk < 0) {
                x1 = x1 + lx;
                y1 = y1;
                pk = pk + 2 * dy;
            }
            else {
                x = x1 + lx;
                y = y1 + ly;
                pk = pk + 2 * dy - 2 * dx;
            }
            putpixel(x1, y1, 34);
        }
    }
    else {
        pk = 2 * dx - dy;
        for (i = 0; i < dy; i++) {
            if (pk < 0) {
                x1 = x1;
                y1 = y1 + ly;
                pk = pk + 2 * dx;
            }
            else {
                x1 = x1 + lx;
                y1 = y1 + ly;
                pk = pk + 2 * dx - 2 * dy;
            }
            putpixel(x1, y1, 34);
        }
    }
    getch();
    closegraph();
}

