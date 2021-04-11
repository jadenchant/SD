#include "IntArray.h"

int IntArray::DEFAULT_SIZE = 4;

IntArray::IntArray(int sz) {
  size = sz;
  elt = new int[size];
  for(int i = 0; i < size; ++i) {
    elt[i] = 0;
  }
}

IntArray::IntArray() {
  size = DEFAULT_SIZE;
  elt = new int[size];
  for(int i = 0; i < size; ++i) {
    elt[i] = 0;
  }
}

IntArray::IntArray(const IntArray &a) {
  size = a.size;
  elt = new int[size];
  for(int i = 0; i < size; ++i) {
    elt[i] = a.elt[i];
  }
}

IntArray& IntArray::operator=(const IntArray &a) {
  size = a.size;
  delete [] elt;
  elt = new int[size];
  for(int i = 0; i < size; ++i) {
    elt[i] = a.elt[i];
  }
  return *this;
}

void IntArray::display() {
  for(int i = 0; i < size; ++i) {
    std::cerr << i << ": " << elt[i] << std::endl;
  }
}

int& IntArray::operator[](int i) {
  if(i >= size || i < 0) {
    std::cerr << "Error, bad index." << std::endl;
  } else {
    return elt[i];
  }
  if(i >= size) {
    return elt[size - 1];
  } else {
    return elt[0];
  }
}