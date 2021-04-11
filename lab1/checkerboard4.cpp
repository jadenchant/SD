#include "../show_mem.h"

int main() {
    _read_image("big.ppm");
    // _print_image();
    int width, height;
    _get_image_dimensions(width, height);
    int quarterW = width / 4;
    int quarterH = height / 4;
    // int pixelRGB = 3 * (width * (height / 2)) + 3 * quarterW;
    int pixelRGB = 3 * (quarterW - 2);
    for(int z = 1; z < 16; z += 2) {
        for(int i = 0; i <= quarterH; ++i) {
            for(int j = 0; j <= quarterW; ++j) {
                _put_uchar(pixelRGB, 0xff);
                _put_uchar(pixelRGB + 1, 0x00);
                _put_uchar(pixelRGB + 2, 0xff);
                pixelRGB += 3;
            }
            pixelRGB += (3 * width) - (3 * (quarterW + 1));
        }
        if((z + 1) % 4 != 0) {
            pixelRGB -= ((quarterH + 1) * (3 * width) - (3 * (quarterW + 1)));
            pixelRGB += (3 * quarterW);
        } else
        {
            if(((z + 1) / 4) % 2 == 1) {
                pixelRGB = 3 * quarterH * width * ((z + 1) / 4);
            } else {
                pixelRGB = 3 * quarterH * width * ((z + 1) / 4) + (3 * (quarterW - 2));
            }
        }
    }
    
    // _print_image();
    _write_image("output.ppm");
}