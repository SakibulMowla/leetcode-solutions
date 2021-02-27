class Solution {
public:
    static bool comp(vector<int> a, vector<int> b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];        
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> ans;
        vector<int> current = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > current[1]) {
                ans.emplace_back(current);
                current = intervals[i];
            } else {
                current[1] = max(current[1], intervals[i][1]);
            }
        }
        ans.emplace_back(current);
        return ans;
    }
};
