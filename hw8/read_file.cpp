#include<iostream>
#include<fstream>
#include<string.h>

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

int main() {
  char room[50];
  read_file("a.txt", room, 50);
  int bytes = 0;
  int arrlen = sizeof(room);
  for(int i = 0; i < arrlen; ++i) {
      if(room[i] != 0) {
          ++bytes;
      } else if((i + 1) < arrlen && room[i + 1] != 0) {
          continue;
      } else {
          break;
      }
  }
  std::cerr << bytes << " bytes.\n";
}

// It does this because the strlen only counts up to the first null byte.
// It counted all of the bytes even the ones after the null byte.