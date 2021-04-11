#include "../show_mem.h"
#include <iostream>

void copy_bytes(int from, int to) {
  int len = 0;
  char d = _get_char(from + len);
  while(0 != d) {
    ++len;
    d = _get_char(from + len);
  }
  // len is the number of non-null bytes to copy
  for (int i = 0; i <= len; ++i) {
    char c = _get_char(from + i);
    _put_char(to + i, c);
  }
}

int main() {
  _put_raw(1, "hi");  // add some data to _global_mem
  copy_bytes(1, 5);   // call the function
  std::cerr << "expecting: hi" << std::endl;
  _print_raw(5);    // print out the result
  _print_newline();
}
