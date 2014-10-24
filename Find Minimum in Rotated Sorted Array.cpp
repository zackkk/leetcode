class Solution {
public:
    // binary search 
    // only the min smaller than its previous element
    int findMin(vector<int> &num) {
        return binarySearch(num, 0, num.size()-1);
    }
    
    int binarySearch(vector<int> &num, int low, int high){
        if(low > high) return num[0]; // already sorted
        if(low == high) return num[low]; // onle one element left
        
        int mid = (low + high) / 2;
        // use mid to check the "smaller" property
        if(low < mid && num[mid] < num[mid-1]) return num[mid];
        if(mid < high && num[mid+1] < num[mid]) return num[mid+1];
        
        if(num[mid] < num[high]) 
            return binarySearch(num, low, mid-1);
        else
            return binarySearch(num, mid+1, high);
    } 
};