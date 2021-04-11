#include<iostream>
using namespace std;

int func(int arg) {
  arg = arg + 2;
  return arg;
}

int funcp(int *argp) {
  *argp = (*argp) + 2;
  return *argp;
}

int main () {
  int i = 17;
  double f = -4.2;
  int *ip = &i;
  double *fp = &f;
  
  std::cerr << "Inital values: i is " << i;
  std::cerr << ", *ip is " << *ip;
  std::cerr << ", f is " << f;
  std::cerr << ", *fp is " << *fp << std::endl;
 
  i *= 3;
  *fp *= 1.5;

  std::cerr << "After multiplying: i is " << i;
  std::cerr << ", *ip is " << *ip;
  std::cerr << ", f is " << f;
  std::cerr << ", *fp is " << *fp << std::endl;

  double f2 = 2.5;
  fp = &f2;
  i *= *ip;

  std::cerr << "f2 assignment: i is " << i;
  std::cerr << ", *ip is " << *ip;
  std::cerr << ", f is " << f;
  std::cerr << ", *fp is " << *fp;
  std::cerr << ", f2 is " << f2 << std::endl;

  std::cerr << "func(i) returns " << func(i);
  std::cerr << ", i is " << i << ", *ip is " << *ip << endl;

  std::cerr << "func(*ip) returns " << func(*ip);
  std::cerr << ", i is " << i << ", *ip is " << *ip << endl;
 
  std::cerr << "funcp(ip) returns " << funcp(ip);
  std::cerr << ", i is " << i << ", *ip is " << *ip << endl;
 
  std::cerr << "funcp(i&) returns " << funcp(&i);
  std::cerr << ", i is " << i << ", *ip is " << *ip << endl;

}