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
        sort(intervals.begin(), intervals.end(), comparator);
        vector<Interval> ret;
        if(intervals.size() == 0) return ret;
        Interval cur = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            // no overlap
            if(intervals[i].start > cur.end){
                ret.push_back(cur);
                cur = intervals[i];
            }
            // overlap
            else{
                int min = cur.start < intervals[i].start ? cur.start : intervals[i].start;
                int max = cur.end   > intervals[i].end   ? cur.end   : intervals[i].end;
                cur.start = min;
                cur.end   = max;
            }
        }
        ret.push_back(cur);
        return ret;
    }
    
};