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

    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> startToN;
        int size = intervals.size();
        vector<int> res(size, -1);

        for (int i=0; i<size; i++) {
            startToN[intervals[i].start] = i;
        }

        sort(intervals.begin(), intervals.end(), comp);

        for (int i=0; i<size; i++) {
            Interval &cur = intervals[i];

            for(int j=i+1; j<size; j++) {
                if (intervals[j].start >= cur.end) {
                    res[startToN[cur.start]] = startToN[intervals[j].start];
                    break;
                }
            }
        }

        return res;
    }
};
