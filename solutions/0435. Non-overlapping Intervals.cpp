class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        int end = intervals[0][0];
        int ans = 0;
        for (auto& interval: intervals) {
            if (end > interval[0]) {
                ans++;
                end = min(end, interval[1]);
            } else {
                end = interval[1];
            }
        }

        return ans;
    }
};
