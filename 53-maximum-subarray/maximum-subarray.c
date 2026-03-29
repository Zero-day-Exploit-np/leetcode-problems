int max(int currentsum, int maxsum) {
    if (currentsum > maxsum) {
        return currentsum;
    }
    return maxsum;
}
int maxSubArray(int* nums, int numsSize) {

    int currentsum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        currentsum += nums[i];
        maxsum=max(currentsum,maxsum);
        if(currentsum<0){
            currentsum=0;
        }
    }

    return maxsum;
}