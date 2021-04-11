#include <iostream>
using namespace std;

long fake_time = 1;

long get_current_time() {
  long ms;
  ms = fake_time++;
  return ms;
}

class Food {
protected:
  bool takeout;
  long long order_time;

public:
  Food(bool t) : takeout(t) { 
    order_time = get_current_time(); 
  }

  void print_takeout() const { 
    cout << " takeout " << takeout << endl; 
  }

  void delay_order() { 
    order_time += 500; 
  }

  virtual void display() const { 
    cout << "Food, glorious food!\n"; 
  }

  virtual void print_order() const = 0;

};

class Nachos : public Food {
public:
  Nachos(bool t) : Food(t) { }

  void print_order() const { 
    cout << "Nachos: "; 
    print_takeout(); 
  }
};

class Quesadilla : public Food {
  bool is_half, just_cheese;

public:
  Quesadilla(bool t, bool h, bool c) : Food(t), is_half(h), just_cheese(c) { }

  void print_order() const { 
    cout << "Quesadilla:  is_half " << is_half;
    cout << " just_cheese " << just_cheese; 
    print_takeout(); 
  }
};

class Ice_Cream : public Food {
  char kind;  // 'C' chocolate, 'V' vanilla, 'T' twist

public:
  Ice_Cream(bool t, char k) : Food(t), kind(k) { }

  void print_order() const { 
    cout << "Ice Cream:  kind " << kind; 
    print_takeout(); 
  }

  void change_flavor(char k2) { 
    kind = k2; 
  }

  void display() const { 
    cout << "I scream, you scream...\n"; 
  }

  void show_more() const { 
    cout << "Base class says: "; 
    Food::display(); 
  }
};

int main() {
  Nachos n1(false);
  Ice_Cream i1(false, 'V'), i2(false, 'T');
  const Ice_Cream ci1 = i1;
  ci1.show_more();
  
  const Food *orders[4];
  orders[0] = &n1;
  orders[1] = &i1;
  orders[2] = &i2;
  orders[3] = &ci1;

  for (int i = 0; i < 4; ++i) {
    orders[i]->print_order();
  }
}
