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

void read_file(const char fname[], char array[], int max_size) {
  std::ifstream f(fname);
  read_stream(f, array, max_size);
  f.close();
}

void server(bool first_time, char fname[]) {
  if(first_time) {
    std::cout << "What file would you like? ";
  } else {
    read_file(fname, _global_mem, mem_size);
  }
}

void client(bool first_time, char fname[]) {
  if(!first_time) {
    std::cout << _global_mem << "\n";
  }
  std::cin.getline(fname, 20);
}


int main() {
  
  for(int i = 0; i < (mem_size - 1); ++i) {
    _global_mem[i] = '~';
  }
  _global_mem[mem_size - 1] = 0;

  bool first_time = true;
  char fname[20];

  while(1) {
    server(first_time, fname);
    client(first_time, fname);
    first_time = false;
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
