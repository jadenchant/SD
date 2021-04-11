#include "../show_mem.h"

int main() {
    _read_image("tiny.ppm");
    int width, height;
    _get_image_dimensions(width, height);
    int numPixel = width * height;
    for (int i = 1; i <= 3*numPixel; i += 3) {
        _put_uchar(i-1,0x00);
        _put_uchar(i,0xff);
        _put_uchar(i+1,0x00);
    }
    _write_image("output.ppm");
}