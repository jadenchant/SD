#include <iostream>

class Rating {
    int id;
    int stars;

public:

  // Constructor
  Rating(int theId, int theStars) {
      id = theId;
      if(theStars >= 1 && theStars <= 5) {
      stars = theStars;
    } else if(theStars > 5) {
      stars = 5;
    } else {
      stars = 1;
    }
  }

  // Setter method for stars
  void set_stars(int newStars) {
    if(newStars >= 1 && newStars <= 5) {
      stars = newStars;
    } else if(newStars > 5) {
      stars = 5;
    } else {
      stars = 1;
    }
  }

  // Getter for id
  int get_id() {
    return id;
  }

  // Getter for starts
  int get_stars() {
    return stars;
  }

  // Display method
  void display(std::ostream &print) {
    print << id << ':';
    for(int i = 1; i <= stars; ++i) {
      print << '*';
    }
  }

};

int main() {
  Rating r(1234, 3);
  std::cerr << "Rating r contains ";   
  r.display(std::cout);  
  std::cerr << std::endl;
  r.set_stars(4);
  std::cerr << "After r.set_stars(4), id=" << r.get_id() 
       << " and stars=" << r.get_stars() << std::endl;

  Rating *arr[8];
  int i;
  for (i = 0;  i < 8;  i++) {
    arr[i] = new Rating(100+i, i);
  }
  std::cerr << "Ratings in array arr:  ";
  for (i = 0;  i < 8;  i++) {
    arr[i]->display(std::cout); std::cerr << "  ";
  }
  std::cerr << std::endl;    
}