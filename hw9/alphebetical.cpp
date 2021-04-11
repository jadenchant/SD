#include "../show_mem.h"
#include <iostream>

bool alphabetical(int i1, int i2) {
    char char1 = _get_uchar(i1);
    char char2 = _get_uchar(i2);
    while(char1 != 0) {
        if(char1 > char2) {
            return true;
        } else if(char1 == char2) {
            ++i1, ++i2;
            char1 = _get_uchar(i1);
            char2 = _get_uchar(i2);
        } else {
            return false;
        }
    }
    if(char1 == 0) {
        return true;
    }
    return false;
}

int main() {
    _put_raw(1, "hi");
    _put_raw(4, "bye");
    _put_raw(10, "byte");
    _put_raw(20, "byee");
    std::cerr << alphabetical(1,2) << std::endl;
    std::cerr << alphabetical(2,10) << std::endl;
    std::cerr << alphabetical(2,20) << std::endl;
}