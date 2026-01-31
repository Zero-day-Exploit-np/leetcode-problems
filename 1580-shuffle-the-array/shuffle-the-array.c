

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* a = (int*)malloc(numsSize * sizeof(int));
    int k = 0;
      for (int i = 0; i < n; i++) {
        a[k++] = nums[i];       
        a[k++] = nums[i + n];   
    }
    *returnSize = numsSize;

    return a;
}