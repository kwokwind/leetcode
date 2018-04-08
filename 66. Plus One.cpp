/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0 itself.
The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0)
            return digits;

        int carry = 0;
        ++digits[digits.size()-1];
        
        for(int i=digits.size()-1; i>=0; --i) {    
            if(digits[i] >= 10) {
                digits[i] -= 10;
                carry = 1;
            }

            if(i >= 1 && carry == 1) {
                digits[i-1] += carry;
                carry = 0;
            }
            
            if(i == 0 && carry == 1) {
                digits.insert(digits.begin(), carry);
            }
        }

        return digits;
    }
};
