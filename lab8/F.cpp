#include <map>
#include <fstream>
#include <iostream>

int main() {
  std::map<std::string, int> num; // Defining new map string and int
  std::map<std::string, std::string> dict; // Defining new map string and string
  std::string fname = "data.txt"; // Name of file
  std::ifstream f(fname.c_str()); // Finds the file based off of its name that was given in the previos line
  std::string t; // Defines a string called t
  while (f >> t) { // Loops for the number of terms
    int n; // Defines a new int n
    f >> n; // imports the values in f to n
    std::string d; // Defines a new string d
    getline(f, d); // retrieves the information strings until it reaches the end of a line
    // std::cerr << "term " << t << " num " << n << " definition " << d << std::endl; // Prints out the data that has been gathered from the file.
    num[t] = n;
    dict[t] = d;
  }
  std::cerr << num["aardvark"] << ' ' << dict["aardvark"] << std::endl;

  for (auto p : num)
    std::cerr << p.first << ' ' << p.second << std::endl;

}