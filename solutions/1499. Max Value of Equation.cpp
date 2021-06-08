class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        int ans = numeric_limits<int>::min();
        for (int i = 0; i < points.size(); i++) {
            while (!pq.empty() && points[i][0] - pq.top().second > k) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans = max(ans, pq.top().first + points[i][0] + points[i][1]);
            }
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }
        return ans;
    }
};
