/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        
        reverse_iterator<vector<int>::iterator> it1 = nums.rbegin();
        int prevNum = *it1;
        int partitionNum = 0;
        while (it1 != nums.rend()) {
            if(*it1 < prevNum) {
                partitionNum = *it1;
                break;
            }
            prevNum = *it1;
            it1++;
        }

        if (it1 == nums.rend()) {
            reverse(nums.begin(), nums.end());
            return;
        }

        reverse_iterator<vector<int>::iterator> it2 = nums.rbegin();
        int changeNum = *it2;
        while (it2 != nums.rend()) {
            if (*it2 > partitionNum) {
                changeNum = *it2;
                break;
            }
            it2++;
        }

        iter_swap(it1, it2);
        // --(rit).base() is to get forward iterator
        reverse(--(it1-1).base(), nums.end());

        return;
    }
};
