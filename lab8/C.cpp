#include <vector>
#include <iostream>

int main() {
  std::vector<int> v = {2, 3, 5, 7, 11};

  std::cerr << v.size() << std::endl;
  for (auto x : v)
    std::cerr << x << std::endl;
  std::cerr << std::endl;

  v.insert(v.begin() + (v.size()/2), 1);
  v.insert(v.begin() + (v.size()/2), 2);
  v.insert(v.begin() + (v.size()/2), 3);

  for (auto x : v)
    std::cerr << x << std::endl;
}