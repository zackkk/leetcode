class Solution {
public:
    // straight forward implementation
    string addBinary(string a, string b) {
        string ret = "";
        int carry = 0;
        int ai = a.size() - 1;
        int bi = b.size() - 1;
        while(ai >= 0 || bi >= 0){
            int sum = carry;
            sum = ai >= 0 ? sum + (a[ai]-'0') : sum;
            sum = bi >= 0 ? sum + (b[bi]-'0') : sum;
            ret = to_string(sum % 2) + ret;
            carry = sum / 2;
            ai--;
            bi--;
        }
        if(carry != 0)
            ret = to_string(carry) + ret;
            
        return ret;
    }
};