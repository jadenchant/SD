void copy_seq(char *s, char *&t) {
    char cs = *s;
    int index = 0;
    int len = 0;

    while(cs != 0) {
        ++len;
        cs = *(s + len);
    }

    t = new char[len + 1];
    cs = *s;

    while(cs != 0) {
        *(t + index) = cs;
        ++index;
        cs = *(s + index);
    }
    *(t + index) = 0;
}