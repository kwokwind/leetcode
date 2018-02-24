/*
Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int limit = 1;
        if (nums.size() < limit) {
            return nums.size();
        }
        
        int i = limit;
        for (int j = limit; j<nums.size(); j++) {
            if(nums[i-limit] != nums[j]) {
                nums[i++] = nums[j];
            }
        }
        
        return i;
    }
};
