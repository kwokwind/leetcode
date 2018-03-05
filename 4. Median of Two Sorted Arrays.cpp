/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
    int m = A.size();
    int n = B.size();
    int total = m + n;
    double ret = 0;
    if ((total & 0x1) == 0x1) {
        // total len is odd
        ret = find_kth(A.begin(), m, B.begin(), n, total/2 + 1);
    } else {
        // total len is even
        ret = (find_kth(A.begin(), m, B.begin(), n, total/2) + find_kth(A.begin(), m, B.begin(), n, total/2 + 1))/2.0;
    }
    return ret;
}
    
private:
int find_kth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k) {
    if (m > n) return find_kth(B, n, A, m, k);
    if (m == 0) return *(B + k - 1);
    if (k == 1) return min(*A, *B);
    
    int ia = min(k/2, m);
    int ib = k - ia;
    
    if (*(A + ia - 1) < *(B + ib - 1)) {
        return find_kth(A + ia, m-ia, B, n, k - ia);
    } else if (*(A + ia - 1) > *(B + ib - 1)) {
        return find_kth(A, m, B+ib, n-ib, k-ib);
    } else {
        return *(A + ia -1);
    }
}
};
