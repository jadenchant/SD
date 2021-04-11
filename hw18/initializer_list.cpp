#include <iostream>

class Cargo {
  double weight;

public:
  Cargo(double w) {
    weight = w;
  }

  double getWeight() {
    return weight;
  }
};

class Ship {
  int num_cargo;
  Cargo c;

public:
  Ship(int num, double w) : c(w) {
    num_cargo = num;
  }

  int getNumCargo() {
    return num_cargo;
  }

  double getCargoWeight() {
    return c.getWeight();
  }
};