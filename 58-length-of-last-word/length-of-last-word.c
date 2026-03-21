int lengthOfLastWord(char* s) {
    int i=strlen(s)-1;
    int count=0;
    while (i >= 0 && isspace((unsigned char)s[i])) {
        i--;
    }

    while (i >= 0 && !isspace((unsigned char)s[i])) {
        count++;
        i--;
    }
    return count;
}