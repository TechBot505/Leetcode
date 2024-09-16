class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for(int i=n-1; i>0; i--) {
            if(digits[i]+carry==10) {
                carry = 1;
                digits[i] = 0;
            }
            else {
                digits[i] = digits[i] + carry;
                carry = 0;
            }
        }
        if(digits[0]+carry==10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        else {
            digits[0] = digits[0] + carry;
            while(digits[0]==0) digits.erase(digits.begin());
        }
        return digits;
    }
};