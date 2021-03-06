/*
Implement int sqrt(int x).
Compute and return the square root of x.
x is guaranteed to be a non-negative integer.
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        
        int low = 1;
        int high = x/2;
        int last = 0;
        
        while (low <= high) {
            int mid = (low + high)/2;
            if (x/mid > mid) {
                low = mid + 1;
                last = mid;
            } else if (x/mid < mid) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        
        return last;
    }
};
