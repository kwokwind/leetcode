/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> maps;
        maps.reserve(nums.size());
        
        int i = 0;
        for (auto it : nums) {
            maps[it] = i;
            i++;
        }
        
        i = 0;
        for (auto it : nums) {
            int another = target - it;
            auto got = maps.find(another);
            if (got != maps.end() && maps[got->first] > i) {
                ret.push_back(i);
                ret.push_back(maps[got->first]);
                break;
            }
            i++;
        }
        
        return ret;
    }
};
