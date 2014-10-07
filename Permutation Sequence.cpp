class Solution {
public:
    // math ---> construct a tree & maintain a remaining chars string
    string getPermutation(int n, int k) {
        if(n == 1) return "1";
        string ret = "";
        string str = "";
        vector<int> f(n+1, 0);  // factorial
        f[1] = 1;
        for(int i = 2; i <= n; i++) f[i] = f[i-1] * i;  
        for(int i = 1; i <= n; i++) str += to_string(i); // string contains "remaining" chars
        k--; // start from 0
        while(str.size() > 2){
            int q = k / f[n-1];  // quotient
            int r = k % f[n-1];  // remainder

            ret += str[q];
            str.erase(q,1); // start pos, length
            n--;
            k = r;
        }
        // two elements remaining
        ret = k == 0 ? ret + str[0] + str[1] : ret + str[1] + str[0];
        return ret;
    }
};