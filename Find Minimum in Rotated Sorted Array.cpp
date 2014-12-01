class Solution {
public:
    // min: smaller than its previous element, will not in the sorted side
    int findMin(vector<int> &num) {
        int lo = 0;
        int hi = num.size()-1;
        while(true){
            if(lo > hi) return num[0];
            if(lo == hi) return num[lo];
            
            int mi = lo + (hi - lo) / 2;
            
            if(lo < mi && num[mi] < num[mi-1]) return num[mi];
            if(mi < hi && num[mi+1] < num[mi]) return num[mi+1];
            
            if(num[mi] < num[hi])
                hi = mi - 1;
            else
                lo = mi + 1;
        }
        return num[lo];
    }
};