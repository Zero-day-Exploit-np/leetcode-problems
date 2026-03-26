class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int numsSize = nums.size();
        sort(nums.begin(), nums.end());

        int ans = nums[0];
        int freq = 1; 
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] == nums[i - 1]) {
                freq++;
            } else {
                freq = 1;
                ans = nums[i];
            }

            if (freq > numsSize / 2) {
                return ans;
            }
        }

        return ans;
    }
};