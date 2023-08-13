//
// Created by Aashiq Shaikh on 8/10/23.
//

#include "bitmap.h"

void line(int x0, int y0, int x1, int y1, bitmap &bm, pixel p)
{
    printf("in line function");

    for (float t=0.; t<1.; t+=.01) {
        int x = x0 + (x1-x0)*t;
        int y = y0 + (y1-y0)*t;
        bm.set(x, y, p);
    }
}

int main()
{
    char *filename = "image.bmp";
    bitmap bm = bitmap(100, 50);

    line(10, 20, 80, 45, bm, pixel());

    bm.save(filename);
    bm.free();
}