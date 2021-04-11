#include<iostream>
#include<chrono>  // used for get_current_time()
#include<sys/stat.h>  // used for get_current_time()

long fake_time = 1;

long get_current_time() {
  long ms;
  if (0) {  // actual time
    using namespace std::chrono;
    ms = duration_cast< milliseconds >(
      system_clock::now().time_since_epoch()).count();
  } else {
    ms = fake_time++;
  }
  return ms;
}

class Food {
protected:
  bool takeout;
  long order_time;

public:
  Food(bool t) : takeout(t) { 
    order_time = get_current_time(); 
  }

  Food(bool t, long o) : takeout(t), order_time(o) { }

  void print_takeout() { 
    std::cerr << " takeout " << takeout << std::endl; 
  }
};

class Nachos : public Food {
public:
  Nachos(bool t) : Food(t) { }

  void print_order() { 
    std::cerr << "Nachos: "; 
    print_takeout(); 
  }
};

class Quesadilla : public Food {
protected:
  bool is_half, just_cheese;

public:
  Quesadilla(bool t, long o, bool h, bool c) : Food(t, o), is_half(h), just_cheese(c) { }

  void print_order() { 
    std::cerr << "Quesadilla:  is_half " << is_half;
    std::cerr << " just_cheese " << just_cheese; 
    print_takeout(); 
  }
};

class Chicken_Quesadilla : public Quesadilla {

public:
  Chicken_Quesadilla(bool t, long o, bool h) : Quesadilla(t, o, h, 0) { }
};


class Ice_Cream : public Food {
  char kind;  // 'C' chocolate, 'V' vanilla, 'T' twist

public:
  Ice_Cream(bool t, char k) : Food(t), kind(k) { }

  void print_order() { 
    std::cerr << "Ice Cream:  kind " << kind; 
    print_takeout(); 
  }
};

int main() {
  Nachos n1(false);
  Ice_Cream i1(true, 'V'), i2(false, 'T');
  i2.print_order();
  Quesadilla q1(true, 2, true, false);
  q1.print_order();
  Chicken_Quesadilla cq1(false, 5, false);
  cq1.print_order();
}
