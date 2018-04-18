/*
Naive: Calculate for each empty cell the number of enemies it can reach in four directions    
Time O(m * n * (m + n))
Space O(1)
rowKills: number of enemies killed in the current row at the current pos
colKills[n]: number of enemies killed in column k (0 <= k < n) in the current row
Time O(3mn) = O(mn)
Space O(n)
*/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        // it is O(mn) or roughly O(3mn), one to iterate through elements, one to scan rows, one to scan columns.
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        if (!m || !n) 
            return 0;
        
        int res = 0, rowKills, colKills[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0 || grid[i][j-1] == 'W') {
                    rowKills = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; ++k)
                        if (grid[i][k] == 'E')
                            ++rowKills;
                }
                if (!i || grid[i-1][j] == 'W') {
                    colKills[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; ++k)
                        if (grid[k][j] == 'E')
                            ++colKills[j];
                }
                if (grid[i][j] == '0')
                    res = max(res, rowKills + colKills[j]);
            }
        }
        
        return res;        
    }
};
