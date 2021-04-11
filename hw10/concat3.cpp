
void concat3(char c1[], char c2[], char result[]) {
    int indexR = 0;
    int indexC1 = 0;
    while(c1[indexC1] != 0) {
        result[indexR] = c1[indexC1];
        ++indexC1;
        ++indexR;
    }
    int indexC2 = 0;
    while(c2[indexC2] != 0) {
        result[indexR] = c2[indexC2];
        ++indexC2;
        ++indexR;
    }
}