void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void reverse(int* nums, int size, int start) {
    int end = size - 1;
    while (start < end) {
        swap(nums, start, end);
        start++;
        end--;
    }
}
void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i >= 0) {
        int j = numsSize - 1;
        while(nums[j]<= nums[i]) {
            j--;
        }
        swap(nums, i, j);
    }
    reverse(nums, numsSize, i + 1);
}