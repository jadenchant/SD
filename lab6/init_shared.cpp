#include <iostream>
#include <fstream>

char *_global_mem;
char fname[] = "/usr/local/cs/cs251/chat/data/Jaden.txt";

void _init_global_mem(int len) {
    for(int i = 0; i < len; ++i) {
        if(i % 100 == 99) {
            _global_mem[i] = '\n';
        } else {
            _global_mem[i] = '~';
        }
    }
}

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

int main(int argc, char **argv) {
    _global_mem = new char[10000];
    _init_global_mem(10000);
    
    unsigned char num_messages = 0;
    _global_mem[10] = num_messages;

    std::ofstream f(fname);
    f.write(_global_mem, 10000);
    f.close();
    
    if(argc == 1 || argc > 2) {
        std::cerr << "Usage: ./chat1 username" << std::endl;
    } else {
        std::cerr << static_cast<int>(_global_mem[10]) << std::endl;
        while(true) {
            std::cerr << argv[1] << "> ";
            char message[80];
            std::cin.getline(message, 80);
            if(message[0] != 0) {
                ++num_messages;
                _global_mem[10] = num_messages;
            }
            std::cerr << static_cast<int>(_global_mem[10]) << std::endl;
        }
    }
}