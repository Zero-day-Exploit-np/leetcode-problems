int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
    int *freq = (int *)calloc(numsSize + 1, sizeof(int));
    int *result = (int *)malloc(2 * sizeof(int));

    int duplicate = -1, missing = -1;

    // Count frequency
    for (int i = 0; i < numsSize; i++)
    {
        freq[nums[i]]++;
    }

    // Find duplicate and missing
    for (int i = 1; i <= numsSize; i++)
    {
        if (freq[i] == 2)
            duplicate = i;
        else if (freq[i] == 0)
            missing = i;
    }

    result[0] = duplicate;
    result[1] = missing;

    *returnSize = 2;

    free(freq);
    return result;
}
