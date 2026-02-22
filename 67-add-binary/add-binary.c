char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int carry = 0;
    // Allocate enough space: max length + 2 (for carry + '\0')
    int maxLen = (i > j ? i : j) + 2;
    char* result = (char*)malloc(maxLen + 1);
    int k = 0;
    while (i >= 0 || j >= 0 || carry) {
        int digitA = (i >= 0) ? a[i] - '0' : 0;
        int digitB = (j >= 0) ? b[j] - '0' : 0;
        int sum = digitA + digitB + carry;
        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
        i--;
        j--;
    }
    result[k] = '\0';
    // Reverse the result string
    for (int start = 0, end = k - 1; start < end; start++, end--) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
    }
    return result;
}