#include "../show_mem.h"

int main() {
    _read_image("tiny.ppm");
    _print_image();
    int width, height;
    _get_image_dimensions(width, height);
    int numPixel = width * height;
    unsigned char greenValue;
    unsigned char doubledValue;
    for (int i = 1; i <= 3*numPixel; i += 3) {
        
        greenValue = _get_uchar(i);
        if(greenValue > 0x80) {
            doubledValue = 0xff;
        } else {
            doubledValue = greenValue * 0x02;
        }
        
        _put_uchar(i,doubledValue);
    }
    _print_image();
    _write_image("output.ppm");
}