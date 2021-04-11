void append_n(char c1[], char c2[], int n) {
    //Find the length of c1
    int lenC1 = 0;
    while(c1[lenC1] != 0) {
        ++lenC1;
    }
    // Adding c2[] up to n (not including at n)
    int indexC1 = lenC1;
    int indexC2 = 0;
    while(indexC2 < n) {
        c1[indexC1] = c2[indexC2];
        ++indexC1; ++indexC2;
    }
    // Adding the null byte to end of c1[]
    c1[indexC1] = 0;
}