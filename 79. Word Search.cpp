/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

class Solution {
public:
    bool exist(const vector<vector<char> > &board, const string& word) {
        int m = 0;
        int n = 0;
        m = board.size();
        if (m != 0)
            n = board[0].size();
        else
            return false;
        
        // define a table to store if this cell is visited already
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                // check each cell, it starts from the first letter(index 0) of the word,
                // dfs function will recursively run depth-first-search algorithm to see if there is a solution
                if (dfs(i, j, 0, board, word, visited))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(int x, int y, int index, const vector<vector<char> > &board, const string& word, vector<vector<bool>>& visited) {
        // all characters in word have been matched, it is a solution
        if (index == word.size()) return true;
        
        // check if x(row index) and y(col index) are valid
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
        
        // if this cell is visited in this round dfs, then return false
        if (visited[x][y]) return false;
        
        if (board[x][y] != word[index])         // character does not match
            return false;
        else {
            // character matches
            visited[x][y] = true;
            // try to dfs next character in word
            bool ret = dfs(x-1, y, index+1, board, word, visited) ||  // check above cell
                       dfs(x+1, y, index+1, board, word, visited) ||  // check below cell
                       dfs(x, y-1, index+1, board, word, visited) ||  // check left cell
                       dfs(x, y+1, index+1, board, word, visited);    // check right cell
            
            // this is important, if a full round(there is solution or not) dfs on a character is done, reset this visited cell to false, since it might be useful for next visiting
            visited[x][y] = false;
            return ret;
        }
    }
};
