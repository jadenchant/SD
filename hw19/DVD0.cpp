#include<iostream>
using namespace std;

class DVD {
  int id;
  char *title;
  char *director;

public:
  // Constructors
  DVD() {
    id = 0;
    title = new char[50];
    title[0] = 0;
    director = new char[50];
    director[0] = 0;
  }

  DVD(int i, const char *t, const char *dir) {
    id = i;

    int lenT = 0;
    while(t[lenT]) { ++lenT; }
    int lenDir = 0;
    while(dir[lenDir]) { ++lenDir; }

    title = new char[lenT + 1];
    director = new char[lenDir + 1];

    for(int j = 0; j <= lenT; ++j) {
      title[j] = t[j];
    }
    for(int j = 0; j <= lenDir; ++j) {
      director[j] = dir[j];
    }
  }

  DVD(DVD &d) {
    id = d.id;

    int lenT = 0;
    while(d.title[lenT]) { ++lenT; }
    int lenDir = 0;
    while(d.director[lenDir]) { ++lenDir; }

    title = new char[lenT + 1];
    director = new char[lenDir + 1];

    for(int j = 0; j <= lenT; ++j) {
      title[j] = d.title[j];
    }
    for(int j = 0; j <= lenDir; ++j) {
      director[j] = d.director[j];
    }
  }

  // Assignment
  DVD &operator=(const DVD &d) {
    id = d.id;
    delete [] title;
    delete [] director;

    int lenT = 0;
    while(d.title[lenT]) { ++lenT; }
    int lenDir = 0;
    while(d.director[lenDir]) { ++lenDir; }

    title = new char[lenT + 1];
    director = new char[lenDir + 1];

    for(int j = 0; j <= lenT; ++j) {
      title[j] = d.title[j];
    }
    for(int j = 0; j <= lenDir; ++j) {
      director[j] = d.director[j];
    }

    return *this;
  }

  // Destructor
  ~DVD() {
    delete [] title;
    delete [] director;
  }

  // Getters
  int getId() {
    return id;
  }

  char* getTitle() {
    return title;
  }

  char* getDirector() {
    return director;
  }

  // Setters
  void setId(int i) {
    id = i;
  }
  
  void setTitle(const char *t) {
    int len = 0;
    while(t[len]) { ++len; }
    delete [] title;
    title = new char[len + 1];
    for(int i = 0; i <= len; ++i) {
      title[i] = t[i];
    }
  }

  void setDirector(const char *d) {
    int len = 0;
    while(d[len]) { ++len; }
    delete [] director;
    director = new char[len + 1];
    for(int i = 0; i <= len; ++i) {
      director[i] = d[i];
    }
  }

  // Display
  void display() {
    cerr << "[" << id << ". " << title << "/" << director << "]";
  }

};
 
int main() {
  char str[] = "Gandhi";
  DVD d1(4, str, "Richard Attenborough");

  DVD d2;
  DVD d3(d1);
  
 
  cout << "After constructors:" << endl;
  d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  
  d2.display(); cout << endl; // [0.  /]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
 
  str[0] = 'X';
 
  cout << "Test for dynamically allocated copies" << endl;
  d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
 
  cout << d2.getId() << endl; // 0
  cout << d1.getTitle() << endl; // Gandhi
  cout << d1.getDirector() << endl; // Richard Attenborough
 
  d1.setId(2);
  d1.setTitle("Shadowlands");
  d2.setDirector("Ingmar Bergman");
 
  cout << "After state changes:" << endl;
  d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
  d2.display(); cout << endl; // [0.  /Ingmar Bergman]
  d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
 
  d3 = d2;
  d2.setTitle("Wild Strawberries");
 
  cout << "After more state changes:" << endl;
  d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
  d2.display(); cout << endl; // [0.  Wild Strawberries/Ingmar Bergman]
  d3.display(); cout << endl; // [0.  /Ingmar Bergman]
  
}
