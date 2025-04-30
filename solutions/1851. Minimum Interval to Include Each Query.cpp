class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        vector<int> queriesSorted = queries;
        sort(queriesSorted.begin(), queriesSorted.end());

        int index = 0, n = intervals.size();
        priority_queue<pair<int, int>> sizeAndEnd;
        unordered_map<int, int> res;

        for (int q: queriesSorted) {
            while (index < n && intervals[index][0] <= q) {
                int l = intervals[index][0], r = intervals[index][1];
                sizeAndEnd.push({-(r - l + 1), r});
                index++;
            }

            while (!sizeAndEnd.empty() && sizeAndEnd.top().second < q) {
                sizeAndEnd.pop();
            }

            res[q] = sizeAndEnd.empty() ? -1 : -sizeAndEnd.top().first;
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = res[queries[i]];
        }

        return ans;
    }
};
