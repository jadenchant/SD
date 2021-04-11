#include"../react.h"

// http://anansi.stolaf.edu/sd/local/?TO=rns202-10.cs.stolaf.edu:25118

int main() {
  init();

  add_yaml("hello.yaml");

  // Can not have it pasted index 4 due to the null byte
  bool hasA = false;
  int index = 1;
  while(_global_mem[index] != 0) {
      if(_global_mem[index] == 'A') {
          hasA = true;
          break;
      }
      ++index;
  }

  if (hasA) {
    _put_raw(5, "Detected an A!");
  } else {
    _put_raw(0, "abcd");
    _put_raw(5, "zyx");
  }

  quit();
}
