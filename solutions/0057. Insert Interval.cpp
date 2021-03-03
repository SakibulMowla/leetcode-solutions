class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        int n = intervals.size();
        
        vector<int> current = newInterval;
        for (int i = 0; i < n; i++) {
            if (intervals[i][1] < current[0]) {
                ans.push_back(intervals[i]);
            } else if (intervals[i][0] > current[1]) {
                ans.push_back(current);
                current = intervals[i];
            } else {
                current[0] = min(current[0], intervals[i][0]);
                current[1] = max(current[1], intervals[i][1]);
            }
        }
        ans.push_back(current);
        
        return ans;
    }
};
