#include<iostream>
const int mem_size = 10000;
char _global_mem[mem_size];

void _put_raw(int index, const char s[]) {
  int len = 0;
  while(s[len] != 0) {
      ++len;
  }
  ++len;

  for(int i = 0; i < len; ++i) {
      _global_mem[index] = s[i];
      ++index;
  }
  _global_mem[index] = 0;
}

int main() {
  for (int i = 0; i < mem_size - 1; ++i) {
    _global_mem[i] = '~';
  }
  _global_mem[mem_size - 1] = 0; 
    
  _put_raw(5, "hello\n");
  std::cout << (_global_mem + 3) << std::endl;
  // output should be ~~hello
}
