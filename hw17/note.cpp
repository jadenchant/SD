#include<iostream>
#include<ostream>
using namespace std;

class Note {
  char *sender;
  char *message;

public:
  Note() {  // this constructor is called a default constructor
    sender = new char[3];
    sender[0] = 'A';  
    sender[1] = 'B';  
    sender[2] = 0;
    
    message = new char[3];
    message[0] = 'h';  
    message[1] = 'i';  
    message[2] = 0;
  }

  ~Note() { 
    delete [] sender; delete [] message; 
  }

  Note(const Note &b) {
    std::cerr << "Calling Copy Constructor" << std::endl;
    int sendLen = 0;
    while(b.sender[sendLen] != 0) {
      ++sendLen;
    }
    ++sendLen;
    int messLen = 0;
    while(b.message[messLen] != 0) {
      ++messLen;
    }
    ++messLen;
    sender = new char[sendLen];
    message = new char[messLen];

    for(int i = 0; i < sendLen; ++i) {
      sender[i] = b.sender[i];
    }

    for(int i = 0; i < messLen; ++i) {
      message[i] = b.sender[i];
    }
  }

  void display(ostream &os) {
    os << "sender: " << sender << " ";
    os << "message: " << message << "\n";
  }
};

int main() {
  Note n1, n2;
  std::cerr << "Before the n1copy" << std::endl;
  Note n1copy(n1);
  n1.display(std::cerr);  // output  sender: AB message: hi
}
