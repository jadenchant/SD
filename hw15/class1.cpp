#include <iostream>

class Chicken {
    bool sexIsFemale;
    int age;
    int eggsPerDay;
    
    public:
        void init(bool a, int b, int c) {
            this->sexIsFemale = a;
            this->age = b;
            this->eggsPerDay = c;
        }

};

int main() {
    Chicken jerald, bella;
    jerald.init(false, 2, 0);
    bella.init(true, 3, 2);
}