#include<iostream>
using namespace std;

class Animal {
protected:
  char *name;
  float weight;

private:
  void init(const char *n, float w) {
    int len = 0;
    while( n[len] ) { 
      ++len; 
    }
    name = new char[len+1];
    for ( int i = 0; i < len+1; ++i ) {
      name[i] = n[i];
    }
    weight = w;
  }

public:
  Animal(const char *n, float w) { 
    init(n, w); 
  }

  Animal(const Animal &a) { 
    init(a.name, a.weight); 
  }

  Animal &operator=(Animal &a) {
    delete [] name;
    init(a.name, a.weight);
    return *this;
  }

  ~Animal() { 
    delete [] name;
    name = 0; 
  }

  float current() const { 
    return weight; 
  }

  float growFast(float s) { 
    weight *= s; 
    return weight; 
  }

  virtual void display() {
    std::cerr << "Animal Name: " << name << "\nWeight: " << weight << std::endl;
  }
};

class HouseCat : public Animal {
  double whisker_len;

public:
  HouseCat(double wl) : Animal("cat", 8) { 
    whisker_len = wl; 
  }

  HouseCat(const HouseCat &hc) : Animal(hc) { 
    whisker_len = hc.whisker_len; 
  }

  ~HouseCat() {}  // this is really not necessary!

  int getLen() { 
    return whisker_len; 
  }

  void trim() { 
    whisker_len /= 2; 
  }

  void display() {
    std::cerr << "Animal Name: " << name << "\nWeight: " << weight << "\nWhisker Length: " << whisker_len << std::endl;
  }
};

int main(){
  HouseCat socks(12), waldo(socks);
  HouseCat garfield = waldo;
  waldo.trim();
  waldo.trim();
  waldo.trim();
  socks.display();
  waldo.display();
  garfield.display();

  HouseCat *gp;
  gp = &garfield;
  gp->display();
}
