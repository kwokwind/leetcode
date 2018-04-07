/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bitset<9> used;
        
        for(size_t i=0; i<9; ++i) {
            used.reset();
            // check row
            for(size_t j=0; j<9; ++j) {
                if(isUsed(board[i][j], used))
                    return false;
            }
            
            used.reset();
            // check column
            for(size_t j=0; j<9; ++j) {
                if(isUsed(board[j][i], used))
                    return false;
            }
        }
        
        // check by 3x3 9 cells
        for(size_t i=0; i<3; ++i) {
            for(size_t j=0; j<3; ++j) {
                used.reset();
                
                // r will start from 0, 3, 6
                for(size_t r=i*3; r<i*3+3; ++r) {
                    // c will start from 0, 3, 6
                    for(size_t c=j*3; c<j*3+3; ++c) {
                        if(isUsed(board[r][c], used))
                            return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool isUsed(char c, bitset<9>& used) {
        if(c == '.') return false;
        
        if(used[c-'1']) return true;
        
        used[c-'1'] = true;
        
        return false;
    }
};
