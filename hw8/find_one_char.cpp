#include "../show_mem.h"
#include <iostream>

int find_one_char(int i, char c) {
    char onC = _get_uchar(i);
    while(onC != 0) {
        if(onC == c) {
            return i;
        }
        ++i;
        onC = _get_uchar(i);
    }
    return i;
}

int main() {
    _put_raw(1, "Hello there!");
    std::cerr << "index of e:" << find_one_char(1,'e') << std::endl;
    std::cerr << "index of v:" << find_one_char(1,'v') << std::endl;
}