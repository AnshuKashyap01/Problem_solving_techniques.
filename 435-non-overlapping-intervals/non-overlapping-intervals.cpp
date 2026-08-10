class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int total = 0;
        sort(intervals.begin(), intervals.end());
        int prev_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= prev_end) {
                prev_end = intervals[i][1];

            } else {
                total += 1;
                prev_end = min(prev_end, intervals[i][1]);
            }
        }
        return total;
    }
    };

