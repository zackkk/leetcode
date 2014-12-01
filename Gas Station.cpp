class Solution {
public:
    // trick: store "gap", then check if it can be filled later
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        vector<int> rem (n, 0);
        int rem_total = 0;
        for(int i = 0; i < n; ++i){
            rem[i] = gas[i] - cost[i];
            rem_total += rem[i];
        }
        
        if(rem_total < 0) return -1;
        
        int ret = 0;
        rem_total = 0;
        for(int i = 0; i < n; ++i){
            rem_total += rem[i];
            if(rem_total < 0){
                rem_total = 0;
                ret = i+1;
            }
        }
        return ret;
    }
};