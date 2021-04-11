#include "../show_mem.h"

int main() {
    _read_image("big.ppm");
    int width, height;
    _get_image_dimensions(width, height);
    int numPixel = width * height;
    char average;
    char r;
    char g;
    char b;
    for (int i = 1; i <= 3*numPixel; i += 3) {
        r = _get_uchar(i-1);
        g = _get_uchar(i);
        b = _get_uchar(i+1);

        average = (r + g + b) / 3;

        _put_uchar(i-1,average);
        _put_uchar(i,average);
        _put_uchar(i+1,average);
    }
    _write_image("output.ppm");
}