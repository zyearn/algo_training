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
    struct Comp {
        bool operator()(Interval &a, Interval &b) {
            return (a.start < b.start);
        
        }
    } comp;

    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int ans = 0;
        int size = intervals.size();
        if (size == 0) return ans;

        Interval cur = intervals[0];
        for (int i=1; i<size; i++) {
            Interval next = intervals[i];
            if (next.start >= cur.end) {
                cur = next;
                continue;
            }

            ans++;
            if (next.end < cur.end) {
                cur = next;
            } 
        }

        return ans;
    }
};
