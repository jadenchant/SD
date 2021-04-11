#include "../show_mem.h"
#include <iostream>

int main() {
    _read_image("big.ppm");
    // _print_image();
    int width, height;
    _get_image_dimensions(width, height);
    // std::cerr << "Dimensions: " << width << " by " << height << std::endl;
    int quarterW = width / 4;
    int quarterH = height / 4;
    int pixelRGB = 3 * (width * (height / 2)) + 3 * quarterW;
    for (int i = 0; i <= quarterH; ++i) {
        for(int j = 0; j <= quarterW; ++j) {
            _put_uchar(pixelRGB, 0xff);
            _put_uchar(pixelRGB + 1, 0x00);
            _put_uchar(pixelRGB + 2, 0xff);
            pixelRGB += 3;
        }
        pixelRGB += (3 * width) - (3 * (quarterW + 1));
    }
    // _print_image();
    _write_image("output.ppm");
}