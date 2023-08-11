//
// Created by Aashiq Shaikh on 8/10/23.
//

#include "bitmap.h"

void line(int x0, int y0, int x1, int y1, char* bitmap)
{

}

int round4(int x)
{
    return x % 4 == 0 ? x : x - x % 4 + 4;
}

int main()
{
    char *filename = "image.bmp";

    bitmap bm = bitmap(100, 50);
    bm.set(0, 1, 255, 255, 0);
    bm.set(0, 10, 255, 0, 0);
    bm.save(filename);
    bm.free();
}