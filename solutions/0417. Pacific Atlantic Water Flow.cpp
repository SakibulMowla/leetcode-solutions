class Solution {
private:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), columns = heights[0].size();
        int pacific = (1 << 0), atlantic = (1 << 1), both = pacific | atlantic;

        vector<vector<int>> reach(rows, vector<int> (columns, 0));
        queue<pair<int, int>> cells;

        for (int i = 0; i < columns; i++) {
            reach[0][i] |= pacific;
            reach[rows - 1][i] |= atlantic;
            cells.push({0, i});
            cells.push({rows - 1, i});
        }

        for (int i = 0; i < rows; i++) {
            reach[i][0] |= pacific;
            reach[i][columns - 1] |= atlantic;
            cells.push({i, 0});
            cells.push({i, columns - 1});
        }

        vector<vector<int>> ans;

        while (!cells.empty()) {
            int x = cells.front().first;
            int y = cells.front().second;
            cells.pop();

            if (reach[x][y] == both) {
                ans.push_back({x, y});
            }

            for (int k = 0; k < 4; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];
                if (newX >= 0 && newX < rows &&
                    newY >= 0 && newY < columns &&
                    heights[newX][newY] >= heights[x][y] &&
                    (reach[newX][newY] & reach[x][y]) != reach[x][y]) {
                        reach[newX][newY] |= reach[x][y];
                        cells.push({newX, newY});
                    }
            }
        }

        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

        return ans;
    }
};
