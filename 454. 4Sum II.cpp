/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l)
there are such that A[i] + B[j] + C[k] + D[l] is zero.
To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500.
All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
Output:
2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ret = 0;
        unordered_map<int, int> cache;
        for(size_t a=0; a<A.size(); ++a) {
            for(size_t b=0; b<B.size(); ++b) {
                cache[A[a]+B[b]] += 1;
            }
        }
        
        for(size_t c=0; c<C.size(); ++c) {
            for(size_t d=0; d<D.size(); ++d) {
                int tmp = 0 - C[c] - D[d];
                auto it = cache.find(tmp);
                if (it == cache.end())
                    continue;
                
                ret += it->second;
            }
        }
        
        return ret;
    }
};
