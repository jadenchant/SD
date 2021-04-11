#include <iostream>
#include"../show_mem.h"

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

int main() {
  Pixel p1;
  p1.red = p1.green = p1.blue = 17;
  int n = p1.red;  // convert to int, prior to printing
  std::cerr << n << "\n";
}