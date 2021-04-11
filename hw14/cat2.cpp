#include<iostream>
using namespace std;

// A feline with a color and a weight in pounds
struct Cat {
  int color;
  double weight;

  void grow() { // increase the weight
    weight *= 1.1;
  }
};

int main() {
  Cat misty, dusty;
  misty.color = 3;
  misty.weight = 2;
  std::cerr << "misty weighs " << misty.weight << std::endl; // 2
  misty.grow();
  std::cerr << "misty weighs " << misty.weight << std::endl; // 2.2
}
