class Solution {
public:
    // step1: find decrease from the end: 2 (3) 6 5 4 1
    // step2: find the first greater then swap: 2 (4) 6 5 (3) 1
    // stpe3: reverse the right part: 2 4 (1 3 5 6)
    // how to prove the correctness? IDK!!!
    void nextPermutation(vector<int> &num) {
        if(num.size() == 0) return;
        
        // step1
        for(int i = num.size() - 2; i >= 0; i--){
            if(num[i] < num[i+1]){ 
                // step2
                for(int j = num.size() - 1; j > i; j--){
                    if(num[j] > num[i]){
                        swap(num, i, j);
                        reverse(num, i+1, num.size()-1); // step3
                        return;
                    }
                }
            }
        }
        reverse(num, 0, num.size()-1); // special case: 6 5 4 3 2 1
    }
    
    void swap(vector<int> &num, int i, int j) {
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }
    void reverse(vector<int> &num, int i, int j){
        for(; i<j; i++, j--)
            swap(num, i, j);
    }
};