class Solution {
private:
    int rows;
    int cols;

    vector<int> dx = { -1, 1, 0, 0 };
    vector<int> dy = { 0, 0, -1, 1 };

    bool check(int x, int y, vector<vector<int> >& grid, vector<vector<bool> >& visited) {
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1 && !visited[x][y];
    }

    bool check(int x, int y, vector<vector<int> >& grid) {
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1;
    }

    int dfs(int x, int y, vector<vector<int> >& grid, vector<vector<bool> >& visited, vector<vector<int> >& compId, int curId) {
        int ret = 1;
        visited[x][y] = true;
        compId[x][y] = curId;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (check(nx, ny, grid, visited)) {
                ret += dfs(nx, ny, grid, visited, compId, curId);
            }
        }

        return ret;
    }

public:
    int largestIsland(vector<vector<int> >& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int ans = 0;
        int comp = 0;
        vector<vector<bool> > visited(rows, vector<bool>(cols, false));
        vector<vector<int> > compId(rows, vector<int>(cols));
        unordered_map<int, int> idToSize;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int compSize = dfs(i, j, grid, visited, compId, comp);
                    ans = max(ans, compSize);
                    idToSize[comp] = compSize;
                    comp++;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    unordered_map<int, int> tmap;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (check(x, y, grid)) {
                            tmap[compId[x][y]] = idToSize[compId[x][y]];
                        }
                    }

                    int sum = 0;
                    for (auto it : tmap) {
                        sum += it.second;
                    }

                    ans = max(ans, sum + 1);
                }
            }
        }

        return ans;
    }
};
