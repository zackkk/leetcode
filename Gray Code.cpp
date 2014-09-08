class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        if(n == 0) return ret;
        ret.push_back(1);
        if(n == 1) return ret;
        
        int power = 1;
        for(int i = 2; i <= n; i++){
            power *= 2;
            vector<int> tmp = ret;
            for(int j = ret.size()-1; j >= 0; j--)
                ret.push_back(tmp[j] + power);
        }
        return ret;
    }
};