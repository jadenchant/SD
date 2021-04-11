
int find_word2(char m[], char q[]) {
    int mI = 0;
    int qI = 0;
    char messageC = m[mI];
    char queryC = q[qI];
    int fSameI = -1;

    while(queryC != 0) {
        while(messageC != 0) {
            if(messageC != queryC) {
                ++mI;
                messageC = m[mI];
            } else if(messageC == queryC && fSameI == -1) {
                fSameI = mI;
                mI = 0;
                messageC = m[mI];
                break;
            } else {
                mI = 0;
                messageC = m[mI];
                break;
            }
        }
        if(messageC == 0) {
            return mI;
        }
        ++qI;
        queryC = q[qI];
    }
    return fSameI;
}