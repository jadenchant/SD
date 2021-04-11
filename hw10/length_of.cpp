
int length_of(char *c) {
    int count = 0;
    while(c[count] != 0) {
        count++;
    }
    return count;
}