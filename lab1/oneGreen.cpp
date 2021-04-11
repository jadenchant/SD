#include "../show_mem.h"

int main() {
    _read_image("tiny.ppm");
    _put_uchar(0, 0x00);
    _put_char(1, 0xff);
    _put_char(2, 0x00);
    _print_image();
    _write_image("output.ppm");
}