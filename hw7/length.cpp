#include "../show_mem.h"
#include <iostream>

int length(int n) {
    int len = 0;
    char c = _get_char(n);
    while (c != 0) {
        ++len;
        c = _get_char(n + len);
    }
    return len;
}

int main() {
  _put_raw(1, "hi");
  if (length(1) == 2) 
    std::cerr << "yes" << std::endl;
  else
    std::cerr << "no" << std::endl;
}
