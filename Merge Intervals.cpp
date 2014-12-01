/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comparator(const Interval &a, const Interval &b){
    return a.start < b.start;
}
 
class Solution {
public:
    // sort, then get the first, merge the remaining to the fisrt
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        int n = intervals.size();
        vector<Interval> ret;
        if(n == 0) return ret;
        
        Interval cur = intervals[0];
        for(int i = 1; i < n; ++i){
            Interval tmp = intervals[i];
            if(tmp.start <= cur.end){
                cur.end = max(cur.end, tmp.end); 
            }
            else{
                ret.push_back(cur);
                cur = tmp;
            }
        }
        ret.push_back(cur);
        return ret;
    }
    
};