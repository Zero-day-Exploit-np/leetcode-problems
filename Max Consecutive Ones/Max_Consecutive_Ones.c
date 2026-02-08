#include <stdio.h>
int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int temp = 0;
    int count = 0;
    if ((numsSize-1)<1)
    {
        if(nums[0]==1){
            return temp;
        }
        return 0;
    }
    for (int i =0; i < numsSize; i++)
    {
        if (nums[i]==1)
        {
            count++;
            if (temp < count)
            {
                temp = count;
            }
        }
        else
        {

            count = 0;
        }
    }
    return temp;
}
int main()
{
    int arr[2] = {0,0};
    // [ 1, 1, 0, 1, 1, 1 /]
    int max = findMaxConsecutiveOnes(arr, 2);
    printf(" %d", max);
    return 0;
}