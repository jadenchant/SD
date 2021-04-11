#include "DVD.h"
#include <iostream>

class DVDArrayP {
private:
  DVD **elt;
  int size;
public:
  static int DEFAULT_SIZE;

  DVDArrayP(int sz);
  DVDArrayP();
  DVDArrayP(DVDArrayP &arr);

  ~DVDArrayP();

  int getSize() { return size; }

  DVDArrayP &operator=(DVDArrayP &arr);

  void display();

  DVD &operator[](int i);
};