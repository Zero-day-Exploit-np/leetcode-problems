/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    int index = 0;
    int i = 0;
    char** arr = malloc( 2*n * sizeof(char*));
    for (int num = 1; num <= n && i<targetSize; num++) {
        arr[index++] = "Push";
        if (target[i] == num){
            i++;
        } else {
            arr[index++] = "Pop";
        }
    }

    *returnSize = index;
    return arr;
}

// 1 3    n=3
// 0 1 2
// 1 2 3

// 1 p p 3
