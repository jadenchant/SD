#include "../show_mem.h"

int main() {
    _read_image("small.ppm");
    // _print_image();
    int width, height;
    _get_image_dimensions(width, height);
    unsigned char a;
    int pixelRGB = 0;
    for (int i = 1; i <= width; ++i) {
        for (int j = 1; j <= 3; ++j) {
            a = _get_uchar(pixelRGB);
            for(int k = 2; k <= height; k += 2) {
                _put_uchar(pixelRGB + (3 * width * k), a);
            }
            ++pixelRGB;
        }
    }
    // _print_image();
    _write_image("output.ppm");
}