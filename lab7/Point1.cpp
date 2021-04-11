#include <iostream>

class Point {
  float x, y, z;

public:
  Point(float a, float b, float c): x(a), y(b), z(c) {}

  void display() const { 
    std::cerr << x << ' ' << y << ' ' << z << '\n'; 
  }

  float &operator[](int index) {
    if (0 == index) return x;
    else if (1 == index) return y;
    else if (2 == index) return z;
    std::cerr << "Error, bad index." << std::endl;
    return x;
  }

};

int main() {
  Point p(1, 2, 3);
  p.display();
  std::cerr << p[1] << std::endl;
  p[0] = 2;
}