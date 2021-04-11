#include<iostream>

class UltimateFrisbee {
  int size;
  float *data;
public:
  UltimateFrisbee() { size = 0; data = 0; }
  UltimateFrisbee(int s) { size = s; data = new float[size]; }
  ~UltimateFrisbee() {
    std::cerr << "bye!" << std::endl;
    if ( data ) delete [] data;
  }

  UltimateFrisbee(UltimateFrisbee &u1) {
    size = u1.size;
    if(u1.data == 0) {
      data = 0;
    } else {
      data = new float[size];
      for(int i = 0; i < size; ++i) {
        data[i] = u1.data[i];
      }
    }
  }

  void display()
    { std::cerr << "size " << size << std::endl;}
};

int main()
{
  UltimateFrisbee g1, g2(3);

  g1.display();
  g2.display();
}
