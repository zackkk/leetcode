class Solution {
public:
    // order tranfer
    string multiply(string num1, string num2) {
        vector<int> ret (num1.size() + num2.size(), 0);
        
        for(int i = num1.size()-1; i >= 0; i--){
            for(int j = num2.size()-1; j >= 0; j--){
                int k = (num1.size()-1-i) + (num2.size()-1-j);  // k starts from 0
                int tmp = (num1[i]-'0') * (num2[j]-'0') + ret[k];
                ret[k] = tmp % 10;
                ret[k+1] += tmp / 10; //  += : bug point
            }
        }
        
        string str = "";
        if(ret.size() == 0) return str;
        int i = ret.size() - 1;
        while(0 == ret[i] && i > 0) i--; // special result: 0
        while(i >= 0) {str += to_string(ret[i]); i--;}
        return str;
    }
};