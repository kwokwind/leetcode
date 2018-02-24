//Write a function to find the longest common prefix string amongst an array of strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        
        for (size_t col=0; col<strs[0].length(); ++col) {
            for (size_t row=1; row<strs.size(); row++) {
                if (strs[0][col] != strs[row][col])
                    return strs[0].substr(0, col);
            }
        }
        
        return strs[0];
    }
};
