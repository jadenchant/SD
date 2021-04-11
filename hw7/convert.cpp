#include "../show_mem.h"
#include <iostream>

float convert_to_celsius(float fahrenheit) {
    return (5./9.)*(fahrenheit - 32.);
}

int main() {
    float c1 = 32.;
    float c2 = -40.;

    float f1 = convert_to_celsius(c1);
    float f2 = convert_to_celsius(c2);

    std::cerr << f1 << std::endl;
    std::cerr << f2 << std::endl;
}