class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ret;
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; --i){
            int sum = carry + digits[i];
            ret.push_back(sum % 10);
            carry = sum / 10;
        }
        if(carry) ret.push_back(carry);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};