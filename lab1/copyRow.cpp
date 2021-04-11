#include "../show_mem.h"
#include <iostream>

int main() {
    _read_image("small.ppm");
    // _print_image();
    int width, height;
    _get_image_dimensions(width, height);
    unsigned char a;
    int pixelRGB = 0;
    for (int i = 1; i <= height; i += 2) {
        for (int j = 1; j <= width; ++j) {
            for (int x = 1; x <= 3; ++x) {
                
                // std::cerr << pixelRGB << std::endl;
                a = _get_uchar(pixelRGB);
                // if ((i + 1) <= height)
                _put_uchar(pixelRGB + (3 * width), a);
                ++pixelRGB;
            }
        }    
        pixelRGB += (3 * width);
    }
    // _print_image();
    _write_image("output.ppm");
}