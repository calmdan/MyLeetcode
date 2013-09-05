/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 //in place!!
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(intervals.size()==0) 
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        if(newInterval.start > intervals.back().end) 
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        for( int i=0;i<intervals.size();i++)
        {
            if(newInterval.end <intervals[i].start) 
            {
                intervals.insert(intervals.begin()+i,newInterval);
                break;
            }
            else if(newInterval.start >intervals[i].end) continue;
            else
            {
                intervals[i].start = min(intervals[i].start,newInterval.start);
                intervals[i].end = max(intervals[i].end,newInterval.end);
                while(i<intervals.size()-1 && intervals[i].end >= intervals[i+1].start)
                {
                    intervals[i].end = max(intervals[i].end,intervals[i+1].end);
                    intervals.erase(intervals.begin()+i+1);
                }
                break;
            }
        }
        return intervals;
    }
};


//新开一个res
class Solution {
public:
   vector<Interval> insert(vector<Interval> &intervals, Interval newInt) {
    /* Assume the original list is already sorted
     * with no overlap. Property maintained after
     * insert. 
     * How about a different structure than vector. 
     * Do an in place insert. ("map" is an option)
     * */
    vector<Interval> v;
    int i = 0;
    int n = intervals.size();
    while(i < n && newInt.start > intervals[i].end)
        v.push_back(intervals[i++]);
    while(i < n && newInt.end >= intervals[i].start) {
        newInt.end = max(newInt.end, intervals[i].end);
        newInt.start = min(newInt.start, intervals[i].start);
        ++i;
    }
    v.push_back(newInt);
    while(i < n)
        v.push_back(intervals[i++]);
    return v;
}
};
