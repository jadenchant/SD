#include<iostream>

// A feline with a color and a weight in pounds
struct Cat {
  int color;
  double weight;
}; // this semicolon is still needed!

// Increase the weight of Cat c
void grow(Cat &c) {
  c.weight *= 1.1;
}

int main() {
  Cat misty, dusty;
  misty.color = 3;
  misty.weight = 2;
  std::cerr << "misty weighs " << misty.weight << std::endl; // 2
  grow(misty);
  std::cerr << "misty weighs " << misty.weight << std::endl; // 2.2
}
