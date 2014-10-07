class Solution {
public:
    // straight-forward implementation
    vector<int> plusOne(vector<int> &digits) {
        if(digits.empty()) return digits;
        
        int i = digits.size() - 1;
        int carry = (digits[i]+1) / 10;
        digits[i] = (digits[i]+1) % 10;
        i--;
        while(carry == 1 && i >= 0){
            int tmp = digits[i] + carry; 
            carry = tmp / 10;
            digits[i] = tmp % 10;
            i--;
        }
        if(carry == 1){ // i is equal to -1 at this moment
            vector<int> ret;
            ret.push_back(1);
            for(int j = 0; j < digits.size(); j++)
                ret.push_back(digits[j]);
            return ret;
        }
        else{
            return digits;
        }
    }
};