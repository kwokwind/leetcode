/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        // temp eventually has the 2 numbers' xor result
        for (auto num : nums) {
            temp ^= num;
        }
        
        // the bits which are 1 in temp indicate those 2 numbers' different bits,
        // it means the 2 nums are different on these bits. so find any one of
        // these specific bits as bit mask
        int bit = 0;
        for (int i=0; i<sizeof(int)*8; ++i) {
            if ((1<<i) & temp) {
                bit = 1 << i;
                break;
            }
        }
        
        // iterate all nums, use mask to check if current num's specific bit is set
        vector<int> result(2, 0);
        for (auto num : nums) {
            if (num & bit) {
                // current num's bit is set, there are 2 posibilities:
                // 1. it is a duplicated number, so it will be cleared by xor when another duplicate number comes up
                // 2. it is one of the different number, so it will be left at the end
                result[0] ^= num;
            } else {
                // current num's bit is not set, there are 2 posibilities:
                // 1. it is a duplicated number, so it will be cleared by xor when another duplicate number comes up
                // 2. it is another different number, so it will be left at the end
                result[1] ^= num;
            }
        }
        return result;
    }
};
