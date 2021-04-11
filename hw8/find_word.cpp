#include "../show_mem.h"
#include <iostream>

int find_word(int m, int q) {
    char messageC = _get_uchar(m);
    char queryC = _get_uchar(q);
    int startingM = m;
    int firstSameCI = -1;
    while(queryC != 0) {

        while(messageC != 0) {
            if(messageC != queryC) {
                ++m;
                messageC = _get_uchar(m);
            } else if(queryC == messageC && firstSameCI == -1) {
                firstSameCI = m;
                messageC = _get_uchar(startingM);
                break;
            } else {
                messageC = _get_uchar(startingM);
                break;
            }
        }
        if(messageC == 0) {
            return m;
        }
        ++q;
        queryC = _get_uchar(q);
    }
    return firstSameCI;
}

int main() {
    _put_raw(1, "Hello there!");
    _put_raw(100, "there");
    _put_raw(200, "three");
    std::cerr << "index of there:" << find_word(1, 100) << std::endl;
    std::cerr << "index of three:" << find_word(1, 200) << std::endl;
}