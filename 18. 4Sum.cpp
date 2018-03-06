/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.
Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if(nums.size() < 4)
            return ret;
        sort(nums.begin(), nums.end());
        
        for(auto a = nums.begin(); a < nums.end()-3; ++a) {
            for( auto b = a + 1; b < nums.end()-2; ++b) {
                auto d = nums.end()-1;
                auto c = b + 1;
                while(c < d) {
                    int sum = *a + *b + *c + *d;
                    if (sum < target) {
                        ++c;
                    } else if (sum > target) {
                        --d;
                    } else {
                        ret.push_back({*a, *b, *c, *d});
                        ++c;
                        --d;
                    }
                }
            }
        }
        sort(ret.begin(), ret.end());
        auto it = unique(ret.begin(), ret.end());
        ret.erase(it, ret.end());
        return ret;
    }
};
