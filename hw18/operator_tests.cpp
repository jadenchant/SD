#include <iostream>

class House {
  double squareft;
  int bedrooms;
  char *address;

public:
  House(double sqft, int bed, const char *add) {
    this->squareft = sqft;
    this->bedrooms = bed;
    int len = 0;
    while(add[len]) { ++len; }
    this->address = new char[len + 1];
    for(int i = 0; i <= len; ++i) {
      this->address[i] = add[i];
    }
  }

  ~House() {
    delete this->address;
  }

  double getSqft() {
    return squareft;
  }

  int operator+(int x) {
    return bedrooms + x;
  }

};

double operator+(House &a, double x) {
  return a.getSqft() + x;
}

int main() {
  House h1(1600.5, 3, "123456 Jonny St, Appleseed, 12345");
  std::cerr << h1 + 1 << std::endl;
  std::cerr << h1 + 12.5 << std::endl;
}