#include <iostream>

int main() {
    char user_input[200];

    bool first_time = true;

    while(1) {
        if(first_time) {
            std::cout << "What is your name? ";
        } else {
            std::cout << "Ok, " << user_input << "\n";
        }

        first_time = false;
        std::cin.getline(user_input, 200);
    }
}

// The User is asked what their name is. Then it replies ok, and then their name. 
// The variable first time makes sure that it only askes the question one time.