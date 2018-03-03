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
