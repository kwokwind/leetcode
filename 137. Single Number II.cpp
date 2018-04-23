/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int bitWidth = sizeof(int) * 8;
        vector<int> counters(bitWidth, 0);
        for (auto num : nums) {
            for (int i=0; i<counters.size(); ++i) {
                counters[i] += (num >> i) & 1;
                if (counters[i] % 3 == 0) {
                    counters[i] = 0;
                }
            }
        }
        
        int ret = 0;
        for (int i=0; i<counters.size(); ++i) {
            ret |= counters[i]<<i;
        }
        
        return ret;
    }
};
