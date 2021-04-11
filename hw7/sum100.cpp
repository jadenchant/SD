#include "../show_mem.h"

int main() {
    int e[100];
    int answer;
    for(int i = 0; i < sizeof(e)/sizeof(e[0]); ++i) {
        answer += e[i];
    }
}