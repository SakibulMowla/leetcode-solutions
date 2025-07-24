class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> points;
        for (int i = 0; i < buildings.size(); i++) {
            auto building = buildings[i];
            points.push_back({building[0], i});
            points.push_back({building[1], i});
        }

        sort(points.begin(), points.end());

        int index = 0;
        int n = points.size();
        priority_queue<pair<int, int>> active;
        vector<vector<int>> ans;

        while (index < n) {
            int pos = points[index].first;
            while (index < n && pos == points[index].first) {
                int bIndex = points[index].second;

                // only if it's the start/left point
                if (pos == buildings[bIndex][0]) {
                    int height = buildings[bIndex][2];
                    int right = buildings[bIndex][1];
                    active.push({height, right});
                }
                index++;
            }

            while (!active.empty() && active.top().second <= pos)
                active.pop();
            
            int height = active.empty() ? 0 : active.top().first;

            if (ans.size() == 0 || height != ans[ans.size() - 1][1])
                ans.push_back({pos, height});
        }

        return ans;
    }
};
