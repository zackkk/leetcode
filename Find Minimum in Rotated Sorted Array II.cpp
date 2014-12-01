class Solution {
public:
    int findMin(vector<int> &num) {
        return binarySearch(num, 0, num.size()-1);
    }
    
    int binarySearch(vector<int> &num, int lo, int hi){
        if(lo > hi) return num[0];
        if(lo == hi) return num[lo];
            
        int mi = lo + (hi - lo) / 2;
            
        if(lo < mi && num[mi] < num[mi-1]) return num[mi];
        if(mi < hi && num[mi+1] < num[mi]) return num[mi+1];
        
        if(num[lo] == num[mi] || num[hi] == num[mi])
            return min(binarySearch(num, lo, mi-1),binarySearch(num, mi+1, hi));
            
        if(num[mi] < num[hi])
            return binarySearch(num, lo, mi-1);
        else
            return binarySearch(num, mi+1, hi);
        
    }
};