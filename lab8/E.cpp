#include <map>
#include <iostream>

int main() {
  std::map<std::string, int> price;
  price["socks"] = 1000;
  price["shoes"] = 3000;
  price["sandles"] = 5000;
  price["gucci flip flops"] = 1000000;
  std::cerr << price["socks"] << std::endl;  
  std::cerr << price["gucci flip flops"] << std::endl;
  std::cerr << price.size() << std::endl;

  for (auto p : price)
    std::cerr << p.first << ' ' << p.second << std::endl;

  if (price.find("boots") == price.end())
    std::cerr << "not found" << std::endl;
  price.erase("socks");
  for (auto p : price)
    std::cerr << p.first << ' ' << p.second << std::endl;
  price.clear();

}