#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    int left = 0;
    int lastSeen[128];

    for (int i = 0; i < 128; i++) {
        lastSeen[i] = -1;
    }

    for (int right = 0; right < n; right++) {
        char currentChar = s[right];

        if (lastSeen[currentChar] >= left) {
            left = lastSeen[currentChar] + 1;
        }

        lastSeen[currentChar] = right;
        maxLength = MAX(maxLength, right - left + 1);
    }

    return maxLength;
}