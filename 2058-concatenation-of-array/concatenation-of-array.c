/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {

    int size = numsSize * 2;
    int* a = (int*)malloc(size * sizeof(int));
    ;
    int n = 0;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < numsSize; i++) {
            a[n++] = nums[i];
        }
    }
    *returnSize = size;
    return a;
}