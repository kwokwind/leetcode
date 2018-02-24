/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int limit = 2;
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
