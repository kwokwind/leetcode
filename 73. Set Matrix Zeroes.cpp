/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

// Method 1
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, int> row0;
        unordered_map<int, int> col0;
        for(int i=0; i<matrix.size(); ++i) {
            for(int j=0; j<matrix[i].size(); ++j)
                if(matrix[i][j] == 0) {
                    row0[i] += 1;
                    col0[j] += 1;
                }
        }
        
        for(auto row : row0) {
            matrix[row.first].assign(matrix[row.first].size(), 0);
        }
        
        for(auto col : col0) {
            for(int i=0; i<matrix.size(); ++i) {
                matrix[i][col.first] = 0;
            }
        }
    }
};

/*
// Method 2: use row0 and col0 to store the 0 flags
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return;
        
        bool row0HasZero = false;
        bool col0HasZero = false;
        for (int i=0; i<matrix[0].size(); ++i) {
            if (matrix[0][i] ==0)
                row0HasZero = true;
        }

        for (int i=0; i<matrix.size(); ++i) {
            if (matrix[i][0] ==0)
                col0HasZero = true;
        }
        
        for (int i=1; i<matrix.size(); ++i) {
            for (int j=1; j<matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    // use row0 and col0 to store the 0 flag,
                    // it will be set to 0 sooner or later
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // there are 2 kinds of 0 in row0 and col0, flagged 0 or original 0,
        // go through the matrix again except row0/col0 to handle flagged 0
        // set row or col to 0 per row0/col0 flags
        for (int i=1; i<matrix.size(); ++i) {
            for (int j=1; j<matrix[i].size(); ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // now we are handling original 0, just set row0/col0 to all 0s if
        // they have original 0s
        if (row0HasZero)
            matrix[0].assign(matrix[0].size(), 0);
        
        if (col0HasZero) {
            for (int i=0; i<matrix.size(); ++i)
                matrix[i][0] = 0;
        }
    }
};
*/
