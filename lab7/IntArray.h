#ifndef _IntArray_H_
#define _IntArray_H_
#include<iostream>

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

#endif  // _IntArray_H_