#include <iostream>

void swap_ptr(int* p0, int* p1, int n) {
    int *ptemp = new int[n];
    for(int i = 0; i < n; ++i) {
        *(ptemp + i) = *(p0 + i);
    }
    for(int i = 0; i < n; ++i) {
        *(p0 + i) = *(p1 + i);
    }
    for(int i = 0; i < n; ++i) {
        *(p1 + i) = *(ptemp + i);
    }
    delete[] ptemp;
}

int main() {
    int *p0 = new int[3];
    *p0 = 1;
    *(p0 + 1) = 2;
    *(p0 + 2) = 3;

    int *p1 = new int[3];
    *p1 = 4;
    *(p1 + 1) = 5;
    *(p1 + 2) = 6;

    swap_ptr(p0, p1, 3);

    std::cerr << "*p0 (p1[0]): " << *p0 << std::endl;
    std::cerr << "*p1 (p1[0]): " << *p1 << std::endl;
}