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
    // point: sorted!!!
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        Interval cur = newInterval;
        for(int i = 0; i < intervals.size(); i++){
            // save directly
            if(intervals[i].end < newInterval.start){
                ret.push_back(intervals[i]);
            }
            // need merge
            else if (intervals[i].start <= newInterval.end){
                int min = cur.start < intervals[i].start ? cur.start : intervals[i].start;
                int max = cur.end   > intervals[i].end   ? cur.end   : intervals[i].end;
                cur.start = min;
                cur.end = max;
            }
            // no more merge
            else{ // intervals[i].start <= newInterval.end
                ret.push_back(cur);    
                cur = intervals[i];
            }
        }
        (cur); // point
        return ret;
    }
};