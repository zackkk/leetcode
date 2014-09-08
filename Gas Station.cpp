class Solution {
public:
    // trick: record gap, then check if it can fill later
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int len = gas.size();
        vector<int> left;
        int leftSum = 0;
        for(int i = 0; i < len; i++){
            left.push_back(gas[i] - cost[i]);
            leftSum += left[i];
        }
        // canCompletePoint doesn't exist
        if(leftSum < 0) 
            return -1;    
        
        // canCompletePoint exist
        int canCompletePointSum = 0;
        int canCompletePoint = 0;
        for(int i = 0; i < len; i++){
            canCompletePointSum += left[i];
            // current canCompletePoint is not working, update it
            if(canCompletePointSum < 0){ 
                canCompletePointSum = 0;
                canCompletePoint = i+1;
            }
        }
        return canCompletePoint;
    }
};