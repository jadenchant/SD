#include <iostream>

class Chicken {
    bool sexIsFemale;
    int age;
    int eggsPerDay;
    
    public:
        Chicken(bool a, int b, int c) {
            this->sexIsFemale = a;
            this->age = b;
            this->eggsPerDay = c;
        }

};

int main() {
    Chicken jerald(false, 2, 0), bella(true, 3, 2);
}