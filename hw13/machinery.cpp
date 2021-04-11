#include <iostream>

struct Machinery {
  int num_blinking_lights;
  double price;
  void increase_price_by(double extra) {
    price += extra;
    std::cerr << price << std::endl;
  }
};

int main() {
    Machinery GNE472 { 1024, 555444.33 };
    GNE472.increase_price_by(100000);
}