#include <fstream>
#include <iostream>

int main() {
    std::ofstream f("new.txt");
    f << "Hello David," << std::endl;
    f << "My name is Jaden." << std::endl;
    f.close();

    std::ifstream g("new.txt");
    char s1[10];
    char s2[10];
    char s3[5];
    char s4[5];
    char s5[5];
    char s6[10];

    g >> s1;
    g >> s2;
    g >> s3;
    g >> s4;
    g >> s5;
    g >> s6;

    std::cerr << s1 << " " << s2 << std::endl;
    std::cerr << s3 << " " << s4 << " " << s5 << " " << s6 << std::endl;
}