#include <iostream>
#include <fstream>
#include <stdio.h>

const int mem_size = 10000;
char _global_mem[mem_size];

// Funtion that goes with read_file
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

// Initializes the global mem
void init_global_mem() {
  for(int i = 0; i < (mem_size - 1); ++i) {
    _global_mem[i] = '~';
  }
  _global_mem[mem_size - 1] = 0;
}

// Basic delete file function
void delete_file(const char *fname) {
  remove(fname);
}

// Reads the request of the .request file and inputs it into global mem
void read_request() {
  // Debugging
  // std::ofstream f("cached_input0");
  // f.write(_global_mem, mem_size - 1);

  read_file(".request", _global_mem, mem_size);
}

// Creates a new file called .response that contains the response from the server 
// and deletes the .request file
void write_response() {
  // Debugging
  // std::ofstream f("out0.mem");
  // f.write(_global_mem, mem_size - 1);

  std::ofstream f(".response");
  f.write(_global_mem, mem_size - 1);
  delete_file(".request");
}

// Main function
int main() {

  init_global_mem();

  read_request();

  const char start[] = "Do you want to either go to the store or go to the movie theater.  choose 1 or 2. ";
  // create several character arrays at once
  const char *option[] = {"Do you want to buy the bread or buy the cheese. choose? ", "Do you want to watch Batman or My Little Pony. choose? ", "The bread is moldy and you die. (restart) ", "The cheese is very smelly, which is normal, but it is acctually from the mold and you die. (restart) ", "You watch the Batman movie and it was terrible, but at least you got to eat popcorn and spill a Diet Coke on your skinny jeans. (restart) ", "It was the best movie ever and were the only person in the movie theater. You also looked under your seat before you left and found a million dollars. (restart) "};
  
  if ('~' == _global_mem[20] || _global_mem[20] > 2) {
    _put_raw(21, start);
    _global_mem[20] = 0;
  } else {
    int state = _global_mem[20];
    if (1 == _global_mem[0]) {
      _put_raw(21, option[2*state + 0]);
      _global_mem[20] = 2*state + 1;
    } else if (2 == _global_mem[0]) {
      _put_raw(21, option[2*state + 1]);
      _global_mem[20] = 2*state + 2;
    } else {
      _put_raw(21, "please choose 1 or 2.\n");
    }
  }

  write_response();
}