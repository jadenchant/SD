#include<iostream>

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void swap(float &a, float &b) {
  float tmp = a;
  a = b;
  b = tmp;
}

void swap(double &a, double &b) {
    double tmp = a;
    a = b;
    b = tmp;
}

int main() {
  int n = 3, m = 4;
  float x = 5, y = 6;
  double i = 2, j = 1;
  swap(n, m);
  swap(x, y);
  swap(i, j);
  std::cerr << n << ' ' << m << '\n';
  std::cerr << x << ' ' << y << '\n';
  std::cerr << i << ' ' << j << '\n';
}
