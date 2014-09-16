class Solution {
public:
    // 1d dp
    int numTrees(int n) {
        vector<int> bst (n+1, 0);
        bst[0] = 1;
        for(unsigned i = 1; i <= n; i++){
            for(unsigned j = 1; j <= i; j++){
                bst[i] += bst[j-1] * bst[i-j];
            }
        }
        return bst[n];
    }
};