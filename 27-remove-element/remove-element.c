int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0)
        return 0;

    int count = 0;

    for (int i = 0; i < numsSize- count; i++) {
        if (nums[i] == val) {
            int j = i;
            count++;
            i--;
            while (j < numsSize-1) {
                nums[j] = nums[j+1];
                j++;
            }
        }
    }
    return (numsSize - count);
}