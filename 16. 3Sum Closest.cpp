/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 0;
        if (nums.size() <= 3) {
            for (auto it : nums) {
                ret += it;
            }
            return ret;
        } else {
            ret = nums[0] + nums[1] + nums[2];
        }

        sort(nums.begin(), nums.end());
        
        auto last = nums.end();
        for(auto i=nums.begin(); i<last-2; ++i) {
            if (i > nums.begin() && *i == *(i-1)) continue;
            
            auto j = i + 1;
            auto k = last - 1;
            while (j < k) {
                int sum = *i + *j + *k;
                
                if (abs(target -sum) < abs(target-ret))
                    ret = sum;
                
                if (sum < target) {
                    ++j;
                    while (j < k && *j == *(j-1)) ++j;
                } else if (sum > target) {
                    --k;
                    while (j < k && *k == *(k+1)) --k;
                } else {                    
                    ++j;
                    while (j < k && *j == *(j-1)) ++j;
                    --k;
                    while (j < k && *k == *(k+1)) --k;
                }
            }
        }
        return ret;
    }
};
