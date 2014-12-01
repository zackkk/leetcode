class Solution {
public:
    // 00, 01
    // 00, 01,, 11, 10
    // 00, 01,  11, 10 ,, 110, 111, 101, 100
    vector<int> grayCode(int n) {
        vector<int> prev;
        prev.push_back(0);
        if(n <= 0) return prev;
        prev.push_back(1);
        int power = 1;
        for(int i = 2; i <= n; ++i){
            power *= 2;
            vector<int> cur = prev;
            for(int j = prev.size()-1; j >= 0; --j)
                cur.push_back(prev[j] + power);
            prev = cur;
        }
        return prev;
    }
};