#include <vector>
#include <string>
#include <fstream>
#include <iostream>

int main() {
  std::vector<std::string> data;
  std::string fname = "expenses.10000";
  std::ifstream f(fname.c_str());
  std::string d;
  while (getline(f, d)) {
    data.push_back(d);
  }

  int count = 0;
  for(auto l : data) {
    if(l[0] < 91 && l[0] > 64) {
      ++count;
    }else if(l[0] < 123 && l[0] > 96) {
      ++count;
    }
  }
  std::cerr << "Number of words: " << count << std::endl;
}