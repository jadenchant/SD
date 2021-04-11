// #include <iostream>

bool is_match(char *s0, int n, char *s1) {
    int indexs0 = n;
    int indexs1 = 0;
    char sc0 = *(s0 + indexs0);
    char sc1 = *s1;
    
    while(sc1 != 0) {
        if(sc0 != sc1) {
            return false;
        } else {
            ++indexs0; ++indexs1;
            sc0 = *(s0 + indexs0); sc1 = *(s1 + indexs1);
        }
    }
    return true;
}

// int main() {
//     char a[] = "Wbyebye";
//     char b[] = "bye";

//     std::cerr << is_match(a, 0, b) << "\n" << std::endl;
//     std::cerr << is_match(a, 1, b) << "\n" << std::endl;
//     std::cerr << is_match(a, 2, b) << "\n" << std::endl;
//     std::cerr << is_match(a, 4, b) << "\n" << std::endl;
// }