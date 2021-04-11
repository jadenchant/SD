#include "DVDArrayP.h"
#include "DVD.h"
#include <iostream>
using namespace std;

int DVDArrayP::DEFAULT_SIZE = 4;

DVDArrayP::DVDArrayP(int sz) : size(sz) {
  elt = new DVD*[size];
  for(int i = 0; i < size; ++i) { elt[i] = 0; }
}

DVDArrayP::DVDArrayP() : size(DEFAULT_SIZE) {
  elt = new DVD*[size];
  for(int i = 0; i < size; ++i) { elt[i] = 0; }
}

DVDArrayP::DVDArrayP(DVDArrayP &arr) : size(arr.size) {
  elt = new DVD*[size];
  for(int i = 0; i < size; ++i) { 
    if(arr.elt[i] == 0) {
      elt[i] = 0;
    } else {
      elt[i] = new DVD(*arr.elt[i]); 
    }
  }
}

DVDArrayP::~DVDArrayP() {
  for(int i = 0; i < size; ++i) {
    if(elt[i] != 0) {
      delete elt[i];
    }
  }
  delete [] elt;
}

DVDArrayP& DVDArrayP::operator=(DVDArrayP &arr) {
  for(int i = 0; i < size; ++i) {
    if(elt[i] != 0) {
      delete elt[i];
    }
  }
  delete [] elt;
  
  size = arr.size;
  elt = new DVD*[size];
  for(int i = 0; i < size; ++i) {
    if(arr.elt[i] == 0) {
      elt[i] = 0;
    } else {
      elt[i] = new DVD(*arr.elt[i]);
    }
  }

  return *this;
}

void DVDArrayP::display() {
  for(int i = 0; i < size; ++i) {
    if(elt[i] != 0) {
      cerr << i << ":  ";
      elt[i]->display();
      cerr << std::endl;
    }
  }
}

DVD& DVDArrayP::operator[](int i) {
  if(i < 0) {
    cerr << "IndexOutOfBounds" << std::endl;
    i = 0;
  } else if(i > (size - 1)) {
    cerr << "IndexOutOfBounds" << std::endl;
    i = size - 1;
    return *elt[size - 1];
  }

  if(elt[i] == 0) {
    elt[i] = new DVD();
  }

  return *elt[i];
}