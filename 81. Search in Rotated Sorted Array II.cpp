/*Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 1 1 2 4 5 6 7 might become 1 2 4 5 6 7 0 1 1).

Write a function to determine if a given target is in the array.

The array may contain duplicates.*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size();
        
        while (first != last) {
            int mid = (first + last)/2;
            
            if (nums[mid] == target)
                return true;
            
            if (nums[first] < nums[mid]) {
                if (nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid + 1;                
            } else if (nums[first] > nums[mid]) {
                if (nums[mid] < target && target <= nums[last-1])
                    first = mid + 1;
                else
                    last = mid;
            } else {
                // nums[first] == nums[mid]
                first++;
            }
        }
        
        return false;
    }
};
