class Solution {
public:
    // 1d dp, list cases for n=1, n=2, n=3... to find out the rule
    int numTrees(int n) {
        vector<int> bst (n+1, 0);
        bst[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                bst[i] += bst[j-1] * bst[i-j];
            }
        }
        return bst[n];
    }
};