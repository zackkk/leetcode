class Solution {
public:
    // order tranfer
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        
        vector<int> ret (m+n, 0);
        for(int i = m-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                int ii = m-1-i; 
                int jj = n-1-j;
                int sum = ret[ii + jj] + (num1[i] - '0') * (num2[j] - '0');
                ret[ii + jj] = sum % 10;
                ret[ii + jj + 1] += (sum / 10);
            }
        }
        
        string str = "";
        if(m == 0 || n == 0) return str;
        
        int j = m+n-1;
        while(j > 0 && ret[j] == 0) j--; // corner case: "0", "0"
        while(j >= 0) { str += to_string(ret[j]); j--; }
        return str;
    }
};