#include "../show_mem.h"

int main() {
    _read_image("small.ppm");
    // _print_image();
    int width, height;
    _get_image_dimensions(width, height);
    int pixelRGB = 0;
    for (int i = 1; i <= (height / 4); ++i) {
        for(int j = 1; j <= (width / 4); ++j) {
            _put_uchar(pixelRGB, 0xff);
            _put_uchar(pixelRGB + 1, 0x00);
            _put_uchar(pixelRGB + 2, 0xff);
            pixelRGB += 3;
        }
        pixelRGB = i * width * 3;
    }
    // _print_image();
    _write_image("output.ppm");
}