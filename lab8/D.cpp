#include <string>
#include <iostream>

int main() {
  std::string s = "What's up?";
  std::cerr << s[5] << s[7] << s[8] << std::endl;  
  std::cerr << "size " << s.size() << std::endl;

  s = s + " ok";
  std::cerr << s << std::endl; 
  std::string s2 = "ji ji";
  std::cerr << (s < s2) << std::endl;

}