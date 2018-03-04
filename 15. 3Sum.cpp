class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3) {
            return ret;
        }
        const int target = 0;
        sort(nums.begin(), nums.end());
        
        for (auto a : nums) {
            cout << a << ",";
        }
        
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
                    while (k > j && *k == *(k+1)) --k;
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
