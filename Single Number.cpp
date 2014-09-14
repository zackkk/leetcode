class Solution {
public:
	// bit manipulation
    int singleNumber(int A[], int n) {
        int ret = 0;
        for(int i = 0; i < n; i++){
            ret = ret ^ A[i];
        }
        return ret;
    }
};