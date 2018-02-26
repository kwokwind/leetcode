class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size();
        
        while(first != last) {
            int mid = (first + last) / 2;
            if (target == nums[mid])
                return mid;
            
            if (nums[first] <= nums[mid]) {
                if (nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[last-1])
                    first = mid + 1;
                else
                    last = mid;
            }
        }

        return -1;
    }
};
