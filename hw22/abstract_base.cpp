#include <iostream>
using namespace std;

class City {
protected:
  int population;
  int size;

public:
  City(int p, int s) : population(p), size(s) { }

  virtual void print() = 0;

  virtual int getNumRooms() = 0;
};

class Building : public City {
  int numRooms;
public:
  Building(int p, int s, int n) : City(p, s), numRooms(n) { }

  void print() {
    cerr << "Population of City: " << population << "\nSize of City: " << size << "\nNumber of Rooms: " << numRooms << endl;
  }

  int getNumRooms() {
    return numRooms;
  }
};

class House : public City {
  int numRooms;
  int people;
public:
  House(int p, int s, int r, int pp) : City(p, s), numRooms(r), people(pp) { }

  void print() {
    cerr << "Population of City: " << population << "\nSize of City: " << size << "\nNumber of Rooms: " << numRooms << "\nPeople Living in Household: " << people << endl;
  }

  int getNumRooms() {
    return numRooms;
  }
};

int main() {
  Building b1(1000, 30000, 12);
  House h1(10000, 231000, 7, 4);
  City *b1p;
  City *h1p;
  b1p = &b1;
  h1p = &h1;
  cerr << "Building 1:" << endl;
  b1p->print();
  cerr << "Number of rooms in Building 1: " << b1p->getNumRooms() << endl;
  cerr << "House 1:" << endl;
  h1p->print();
  cerr << "Number of rooms in House 1: " << h1p->getNumRooms() << endl; 
}