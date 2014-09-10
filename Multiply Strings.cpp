class Solution {
public:
    // order tranfer
    string multiply(string num1, string num2) {
        vector<int> ret;
        for(int i = 0; i < num1.size()+num2.size(); i++)
            ret.push_back(0);
        for(int i = num1.size()-1; i >= 0; i--){
            for(int j = num2.size()-1; j >= 0; j--){
                // retIndex will be increasing
                int retIndex = (num1.size()-1-i) + (num2.size()-1-j);
                int tmpRes = (num1[i]-'0') * (num2[j]-'0') + ret[retIndex];
                ret[retIndex] = tmpRes % 10;
                ret[retIndex+1] += tmpRes / 10; //  += : bug point
            }
        }
        
        string str = "";
        if(0 == ret.size()) return str;
        int i = ret.size()-1;
        while(0 == ret[i] && i > 0) i--; // special result: 0
        while(i >= 0) {str += to_string(ret[i]); i--;}
        return str;
    }
};