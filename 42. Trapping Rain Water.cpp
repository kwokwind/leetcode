/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

/*
for each bar, find the left max bar and right max bar, the water it can contain is "max(maxLeft, maxRight) - currentHeight"
*/

// Method 2
// 1. find the peak bar's index
// 2. scan from left to peakIndex to calculate the water, only need to care the maxLeft
// 2. scan from right to peakIndex to calculate the water, only need to care the maxRight

class Solution {
public:
    int trap(vector<int>& height) {
        size_t len = height.size();
        
        if (len < 3)
            return 0;
        
        int peak = 0;
        int peakIndex = 0;
        for (size_t i=0; i<len; ++i) {
            if(height[i] > peak) {
                peak = height[i];
                peakIndex = i;
            }
        }
        
        int water = 0;
        
        int maxLeft = 0;
        for (size_t i=0; i<peakIndex; ++i) {
            int diff = maxLeft - height[i];
            if (diff > 0)
                water += diff;
            else
                maxLeft = height[i];
        }
        
        int maxRight = 0;
        for (size_t i=len-1; i>peakIndex; --i) {
            int diff = maxRight - height[i];
            if (diff > 0)
                water += diff;
            else
                maxRight = height[i];
        }
        
        return water;
    }
};

/* Method 01
// 1. scan from left to right to find each bar's maxLeft
// 2. scan from right to left to find each bar's maxRight
// 3. go through the vector again to calculate the water

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        
        size_t len = height.size();
        
        int water = 0;
        
        for (size_t i=1; i<len; ++i) {
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
            maxRight[len-i-1] = max(maxRight[len-i], height[len-i]);
        }
        
        for (size_t i=1; i<len; ++i) {
            int l = min(maxLeft[i], maxRight[i]);
            int diff = l - height[i];
            if (diff > 0) water += diff;
        }
        
        return water;
    }
};
*/

/* Method 3
class Solution {
public:
int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            cout<<"current=" << current<<",height[current]="<<height[current]<<", height[st.top()]="<<height[st.top()]<<", st.top()=" << st.top() << endl;
            int top = st.top();
            st.pop();
            if (st.empty()) {
                cout << "break here!" << endl;
                break;
            }
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            cout << "distance=" << distance<<", bounded_height=" << bounded_height << endl;
            ans += distance * bounded_height;
            cout << "ans=" << ans << endl;
        }
        st.push(current++);
    }
    return ans;
}
};
*/
