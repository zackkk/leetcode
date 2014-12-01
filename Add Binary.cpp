class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        string ret = "";
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0) sum += (a[i] - '0');
            if(j >= 0) sum += (b[j] - '0');
            int rem = sum % 2;
            carry = sum / 2;
            ret += to_string(rem);
            i--;
            j--;
        }
        if(carry) 
            ret += to_string(carry);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};