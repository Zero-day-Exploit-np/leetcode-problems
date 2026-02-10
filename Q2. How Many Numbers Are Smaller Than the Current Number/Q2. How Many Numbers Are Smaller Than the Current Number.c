/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
        int* arr=malloc(numsSize*sizeof(int));
        int count=0;
        int key;
        for(int i=0; i<numsSize; i++){
            key=nums[i];
            for(int j=0; j<numsSize; j++){
                if(key>nums[j]){
                    count++;
                }
            }
            arr[i]=count;
            count=0;
        }    
        *returnSize=numsSize;
        return arr;
}
