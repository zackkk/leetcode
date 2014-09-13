class Solution {
public:
    // straight forward solution
    vector<int> getRow(int rowIndex) {
        vector<int> vec;
        
        vec.push_back(1);
        if(0 == rowIndex) 
            return vec;
            
        vec.push_back(1);
        if(1 == rowIndex)
            return vec;
            
        for(int i = 2; i <= rowIndex; i++){
            for(int j = vec.size() - 1; j >= 1; j--){
                vec[j] = vec[j] + vec[j-1];
            }
            vec.push_back(1);
        }
        return vec;
    }
};