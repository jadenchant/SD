#include <iostream>

int main(int argc, char **argv) {
    unsigned char num_messages = 0;
    if(argc == 1 || argc > 2) {
        std::cerr << "Usage: ./chat1 username" << std::endl;
    } else {
        std::cerr << static_cast<int>(num_messages) << std::endl;
        while(true) {
            std::cerr << argv[1] << "> ";
            char message[80];
            std::cin.getline(message, 80);
            if(message[0] != 0) {
                ++num_messages;
            }
            std::cerr << static_cast<int>(num_messages) << std::endl;
        }
    }
}