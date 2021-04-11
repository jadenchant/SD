#include "../show_mem.h"

int main() {
  _put_raw(0, ".");  // store a dot
  _put_raw(2, "\n"); // store newline

  for (int z = 0; z < 3; ++z) {
    _print_raw(0);  // print a dot
  }
  _print_raw(2);  // print newline

    // Exercise 1
    for(int i = 100; i >= 0; i -= 5) {
        
    }

    // Exercise 2
    int n = 1;
    while(n <= 100) {
        n *= 2;
    }

    // Exercise 3
    for (int i = 0; i <= 100; i += 2) {
        if(i % 5 == 0) {
            continue;
        }
        n = i / 2;
    }
}

