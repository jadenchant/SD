#include<iostream>
#include"../show_mem.h"

int main() {
  init();
  _put_int(10, 4);
  short *arr = reinterpret_cast<short *>(_global_mem + 20);
  _put_short(20, (short)1);
  _put_short(22, (short)2);
  _put_short(24, (short)3);

  for(int i = 0; i < 3; ++i) {
    std::cerr << arr[i] << std::endl;
  }
}