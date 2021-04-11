#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <sys/stat.h>
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

// Waits a certain amout of time before running the next function / line of code
void pause(float p) {
  timespec t;
  t.tv_sec = (int)p;
  p -= (int)p;
  t.tv_nsec = (long)(1000000000 * (double)p);

  nanosleep(&t, 0);
}

// Checks to see if the file exists
bool file_exists(const char *fname) {
  struct stat sb;   
  return stat(fname, &sb) == 0;
}

// Gets the user input and adds it to global mem
void talk_to_user() {
  std::cout << (_global_mem + 21) << "\n";
  std::cin.getline(_global_mem, 20);
}

// Function that waits to get a response from the server / .request file
void talk_to_server() {
  std::ofstream q(".request");
  q.write(_global_mem, mem_size - 1);
  q.close();

  while(1) {
    pause(0.25);
    if (!file_exists(".request")) {
      read_file(".response", _global_mem, mem_size);
      delete_file(".response");
      return;
    }
  }
}

// Main function
int main() {
  init_global_mem();
  while(1) {
    talk_to_server();  
    talk_to_user();
  }
}
