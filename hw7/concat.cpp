#include "../show_mem.h"
#include <iostream>

void concatenate(int i1, int i2, int j) {

    int len1 = 0;
    char c1 = _get_char(i1);
    
    while (c1 != 0) {
        ++len1;
        c1 = _get_char(i1 + len1);
    }

    for (int i = 0; i <= len1; ++i) {
        char c = _get_char(i1 + i);
        _put_char(j + i, c);
    }

    int len2 = 0;
    char c2 = _get_char(i2);
    while (c2 != 0) {
        ++len2;
        c2 = _get_char(i2 + len2);
    }

    for (int i = 0; i <= len2; ++i) {
        char c = _get_char(i2 + i);
        _put_char(j + i + len1, c);
    }
}

int main() {
    _put_raw(1, "hi");
    _put_raw(4, "bye");

    concatenate(1, 4, 8);
    _print_raw(8);
    concatenate(4,1, 8);
    _print_raw(8);
}