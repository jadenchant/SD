#include <iostream>

short global_1 = 3, global_2 = 4;

short &get_first() { 
  return global_1; 
}

short &get_one(int i) {
    if(i) {
        return global_2;
    } else {
        return global_1;
    }
}

int main() {
  get_first() = 5;  // error!
  std::cerr << global_1 << std::endl;
  get_one(0) = 1;
  get_one(1) = 2;
}
