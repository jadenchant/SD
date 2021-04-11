#include<fstream>
#include<string.h>

int main() {
  char greeting[] = "hello everybody!\n";
  int n = strlen(greeting);
  greeting[5] = 0;
  std::ofstream f("a.txt");  // create file stream object
  f.write(greeting, n);  
  f.close();
}