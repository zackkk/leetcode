class Solution {
public:
    // straight-forward implementation
    vector<int> getRow(int rowIndex) {
        vector<int> vec;
        
        vec.push_back(1);
        if(rowIndex == 0) return vec;
            
        vec.push_back(1);
        if(rowIndex == 1) return vec;
            
        for(int i = 2; i <= rowIndex; i++){
            for(int j = vec.size() - 1; j >= 1; j--){
                vec[j] = vec[j] + vec[j-1];
            }
            vec.push_back(1);
        }
        return vec;
    }
};