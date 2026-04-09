char* countAndSay(int n) {
    char *result = (char*)malloc(5000);
    strcpy(result, "1");

    for (int i = 2; i <= n; i++) {
        char *temp = (char*)malloc(5000);
        temp[0] = '\0';

        int len = strlen(result);
        int count = 1;

        for (int j = 1; j <= len; j++) {
            if (j < len && result[j] == result[j - 1]) {
                count++;
            } else {
                char part[20];
                sprintf(part, "%d%c", count, result[j - 1]);
                strcat(temp, part);
                count = 1;
            }
        }

        free(result);
        result = temp;
    }

    return result;
}
