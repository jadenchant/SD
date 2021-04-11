// #include <iostream>

void reverse(char *s) {
    int len = 0;
    while(*(s + len) != 0) {
        ++len;
    }

    // std::cerr << len << std::endl;
    
    char *temp = new char[len];
    char sc = *s;
    int index = 0;
    while(sc != 0) {
        *(temp + index) = sc;
        ++index;
        sc = *(s + index);
    }
    // std::cerr << temp << std::endl;

    index = 0;
    for(int i = len - 1; i >= 0; --i) {
        *(s + i) = *(temp + index);
        ++index;
    }
}

// int main() {
//   char a[] = "hi";
//   char b[] = "bye";

//   reverse(a);
//   reverse(b);
//   std::cerr << a << std::endl;
//   std::cerr << b << std::endl;
// }