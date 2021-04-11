#include <iostream>
#include <fstream>

const int mem_size = 10000;
char _global_mem[mem_size];

void read_stream(std::istream &f, char array[], int max_size) {
  int num_bytes;
  if (f.good()) {
    f.read(array, max_size);
    if (f) {
      std::cerr << "Warning in read_stream:  did not reach end of stream after " << max_size << " characters.";
      num_bytes = max_size - 1;
    } else {
      num_bytes = f.gcount();
      if (num_bytes >= max_size) num_bytes = max_size - 1;
    }
  } else {
    std::cerr << "Warning in read_stream: unable to read anything\n";
    num_bytes = 0;
  }
  array[num_bytes] = 0;  // assign null at end
}

// Reads the file based on the name of the file, the content, and the max size of the array
void read_file(const char fname[], char array[], int max_size) {
  std::ifstream f(fname);
  read_stream(f, array, (max_size - 21));
  f.close();
}

// Puts raw characters into global mem
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

void init_global_mem() {
  for(int i = 0; i < (mem_size - 1); ++i) {
    _global_mem[i] = '~';
  }
  _global_mem[mem_size - 1] = 0;
}

void server() {
  if(_global_mem[20] == '~') {
    _put_raw(21, "What file would you like? ");
  } else {
    read_file(_global_mem, (_global_mem + 21), mem_size);
  }
  _global_mem[20] = 'X';
}

void client() {
  std::cout << (_global_mem + 21) << "\n";
  std::cin.getline(_global_mem, 20);
}


int main() {

  init_global_mem();

  while(1) {
    server();
    client();
  }

    // char fname[20];
    // char content[1000];

    // bool first_time = true;

    // while(1) {
    //     if(first_time) {
    //         std::cout << "What file would you like? ";
    //     } else {
    //         read_file(fname, content, 1000);
    //         std::cout << content << "\n";
    //     }

    //     first_time = false;
    //     std::cin.getline(fname,20);
    // }
}
