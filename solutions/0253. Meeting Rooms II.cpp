class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int ans = 0, qsz = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto interval: intervals) {
            while (!pq.empty() && pq.top() <= interval[0]) {
                pq.pop();
                qsz--;
            }
            pq.push(interval[1]);
            qsz++;
            ans = max(ans, qsz);
        }

        return ans;
    }
};
