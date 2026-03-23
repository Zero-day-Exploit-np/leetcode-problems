int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int capacity = 16;

    int **result = (int **)malloc(capacity * sizeof(int *));
    *returnColumnSizes = (int *)malloc(capacity * sizeof(int));

    if (numsSize < 4)
        return result;

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {
                long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {

                    // resize if needed
                    if (*returnSize == capacity) {
                        capacity *= 2;
                        result = realloc(result, capacity * sizeof(int *));
                        *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
                    }

                    int *quad = (int *)malloc(4 * sizeof(int));
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[left];
                    quad[3] = nums[right];

                    result[*returnSize] = quad;
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;

                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}