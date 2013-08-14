//always run time erroe, don't know why
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
    static bool mycmp(Interval i1,Interval i2)
    {
        return i1.start <= i2.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> cc;
    sort(intervals.begin(), intervals.end(), mycmp);
    int n = intervals.size();
    int i = 0;
    while(i < n) {
        cc.push_back(intervals[i++]);
        while(i < n && intervals[i].start <= cc.back().end)
            cc.back().end = max(cc.back().end, intervals[i++].end);
    }
    return cc;
}
};
