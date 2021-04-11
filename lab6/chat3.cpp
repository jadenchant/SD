#include <iostream>
#include <fstream>

char *_global_mem;
int _mem_size = 10000;
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

void write_file(const char fname[]) {
    std::ofstream f(fname);
    f.write(_global_mem, _mem_size);
    f.close();
}

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
}

void write_message(int index, const char author[], const char msg[]) {
  _put_raw(index + 9, author);
  _put_raw(index + 20, msg);
}

void display_messages(int num_messages) {
  read_file(fname, _global_mem, _mem_size + 1);
  for(int i = 1, currentIndex = 109; i <= num_messages; ++i, currentIndex += 100) {
    int lenAuthor = 0;
    while(_global_mem[currentIndex + lenAuthor] != 0) { ++lenAuthor; }
    ++lenAuthor;
    int lenMessage = 0;
    while(_global_mem[currentIndex + 11 + lenMessage] != 0) { ++lenMessage; }
    ++lenMessage;
    
    char author[lenAuthor];
    for(int j = 0; j < lenAuthor; ++j) {
      author[j] = _global_mem[currentIndex + j];
    }
    char message[lenMessage];
    for(int j = 0; j < lenMessage; ++j) {
      message[j] = _global_mem[currentIndex + 11 + j];
    }

    std::cerr << author << "> " << message << std::endl;
  }
}

int main(int argc, char **argv) {
    _global_mem = new char[_mem_size];
    read_file(fname, _global_mem, _mem_size + 1);
    
    if(argc == 1 || argc > 2) {
        std::cerr << "Usage: ./chat1 username" << std::endl;
    } else {
        while(true) {
            display_messages(_global_mem[10]);
            std::cerr << argv[1] << "> ";
            char message[80];
            std::cin.getline(message, 80);
            read_file(fname, _global_mem, _mem_size + 1);
            if(message[0] != 0) {
                ++_global_mem[10];
                write_message(100 * _global_mem[10], argv[1], message);
                write_file(fname);
            }
            std::cerr << '\n';
        }
    }
}