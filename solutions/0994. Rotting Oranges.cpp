class Solution {
private:
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> rottens;
        int fresh = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    rottens.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int ans = 0;
        while (!rottens.empty()) {
            int x = rottens.front().first;
            int y = rottens.front().second;
            rottens.pop();
            for (int k = 0; k < 4; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];
                if (newX >= 0 && newX < rows &&
                    newY >= 0 && newY < cols &&
                    grid[newX][newY] == 1) {
                        grid[newX][newY] = grid[x][y] + 1;
                        rottens.push({newX, newY});
                        fresh--;
                        ans = max(ans, grid[newX][newY] - 2);
                    }
            }
        }

        return fresh == 0 ? ans : -1;
    }
};
