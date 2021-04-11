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
}