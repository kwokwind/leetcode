/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3) {
            return ret;
        }
        const int target = 0;
        sort(nums.begin(), nums.end());
        
        auto last = nums.end();
        for(auto i=nums.begin(); i<last-2; ++i) {
            if (i > nums.begin() && *i == *(i-1)) continue;
            
            auto j = i + 1;
            auto k = last - 1;
            while (j < k) {
                if ((*i + *j + *k) < target) {
                    ++j;
                    while (j < k && *j == *(j-1)) ++j;
                } else if ((*i + *j + *k) > target) {
                    --k;
                    while (j < k && *k == *(k+1)) --k;
                } else {
                    ret.push_back({*i,*j,*k});
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
