/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    // 1. add newIntervals into intervals ---> messy
    // 2. add intervals into newInterval
    // point: sorted, maintain a current interval
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        for(Interval cur : intervals){
            if(cur.end < newInterval.start){
                ret.push_back(cur);
            }
            else if(cur.start > newInterval.end){
                ret.push_back(newInterval);
                newInterval = cur;
            }
            else{
                newInterval.start = min(cur.start, newInterval.start);
                newInterval.end   = max(cur.end, newInterval.end);
            }
        }
        ret.push_back(newInterval);
        return ret;
    }
};