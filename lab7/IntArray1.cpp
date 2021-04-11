#include <iostream>

class IntArray {
private:
  int *elt;
  int size;

public:
  static int DEFAULT_SIZE;

  IntArray(int sz);
  IntArray();
  IntArray(const IntArray &a);
  ~IntArray() { delete [] elt; }
  IntArray &operator=(const IntArray &a);
  int getSize() const { return size; }
  void display();
  int &operator[](int i);
};

int IntArray::DEFAULT_SIZE = 4;

int main() {

  IntArray arr1, arr2(3);
  std::cerr << "arr1 has size " << arr1.getSize() << std::endl;
  arr2.display(); std::cerr << std::endl;
 
  arr2[1] = 24;
  arr2.display(); std::cerr << std::endl;
  arr2[389]; // should display an error, but not crash
 
  IntArray arr3(arr2);
  arr3.display();
  arr1 = arr3;
  arr1.display();
  arr2[2] = 63;
  (arr1 = arr2)[0] = -99;
  arr1.display();
}

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