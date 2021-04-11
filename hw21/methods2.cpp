#include <iostream>

class BodyOfWater {
protected:
  int volume;
  bool isFreshWater;
  
public:
  BodyOfWater(int v, bool fw) : volume(v), isFreshWater(fw) { }

  void printVolume() {
    std::cerr << "Volume of Water: " << volume << " miles cubed" << std::endl;
  }

  void print() {
    std::cerr << "Volume of Water: " << volume << " miles cubed" << "\nIs Fresh Water: " << isFreshWater << std::endl;
  }
};

class Lake : public BodyOfWater{
  char *name;
  int species;

public:
  Lake(const char n[], int s, int v, bool fw) : BodyOfWater(v, fw), species(s) {
    int len = 0;
    while(n[len++]) { }
    name = new char[len];
    for(int i = 0; i < len; ++i) {
      name[i] = n[i];
    }
  }

  void printName() {
    std::cerr << "Name of Lake: " << name << std::endl;
  }

  void print() {
    std::cerr << "Name of Lake: " << name << "\nNumber of Species: " << species << std::endl;
  }

  void printAll() {
    this->print();
    BodyOfWater::print();
  }
};

void newLine() {
  std::cerr << std::endl;
}

int main() {
  BodyOfWater w1(1000, true);
  Lake l1("Lake Superior", 100, 5042010, true);
  BodyOfWater *wp = &l1;
  BodyOfWater &wr = l1;
  std::cerr << "Body of Water 1" << std::endl;
  w1.printVolume();
  w1.print();
  
  newLine();
  
  std::cerr << "Lake Superior" << std::endl;
  l1.printName();
  l1.print();
  newLine();
  l1.printAll();

  newLine();

  std::cerr << "Lake Superior ref" << std::endl;
  wr.printVolume();
  wr.print();

  newLine();

  std::cerr << "Lake Superior pointer" << std::endl;
  wp->printVolume();
  wp->print();
}