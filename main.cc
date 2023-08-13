//
// Created by Aashiq Shaikh on 8/10/23.
//

#include "bitmap.h"
#include <algorithm>


void line(int x0, int y0, int x1, int y1, bitmap &bm, pixel p)
{
//    printf("r: %i", (int)p.r());
    bool steep = false;
    // if the line is steep, transpose the image
    if(std::abs(x0-x1)<std::abs(y0-y1)) {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    if(x0>x1) { // make it left-to-right
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    for (int x=x0; x<=x1; x++) {
        float t = (x-x0)/(float)(x1-x0);
        int y = y0*(1.-t) + y1*t;
        if(steep) {
            bm.set(y, x, p); // if transposed, de-transpose
        } else {
            bm.set(x, y, p);
        }
    }
}

int main()
{
    char *filename = "image.bmp";
    bitmap bm = bitmap(100, 100);

    line(13, 20, 80, 40, bm, pixel::white());
    line(20, 13, 40, 80, bm, pixel::blue());
    line(80, 40, 13, 20, bm, pixel::blue());

    bm.save(filename);
    bm.free();
}