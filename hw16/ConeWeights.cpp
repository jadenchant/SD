#include<iostream>

class ConeWeights {
  int num_cones;
  float *data;
public:
  // constructor
  ConeWeights(int n) { 
    num_cones = n; 
    data = new float[num_cones]; 
  }

  // destructor
  ~ConeWeights() { 
    std::cerr << "bye!" << std::endl; 
    delete [] data; 
  }

  void assign_cone_weight(int i, float w) { 
    data[i] = w; 
  }
  
  void display() { 
    std::cerr << "num_cones " << num_cones << std::endl;
  }

  void multi3() {
      for(int i = 0; i < num_cones; ++i) {
          data[i] *= 3;
      }
  }

  void increase_size() {
      float *temp = new float[num_cones + 1];
      for(int i = 0; i < num_cones; ++i) {
          temp[i] = data[i];
      }
      temp[num_cones] = 0;
      delete [] data;
      data = temp;
      ++num_cones;
  }
};

int main() {
  ConeWeights cs(3); // constructor is automatically called here
  cs.assign_cone_weight(0, 125.5);
  cs.display();
  cs.multi3();
  cs.increase_size();
  cs.display();
  // invisible feature:  the destructor is automatically called here!
}
