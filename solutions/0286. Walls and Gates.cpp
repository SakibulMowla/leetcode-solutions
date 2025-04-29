// Time - O(n * m)
// Memory - O(n * m)

class Solution {
private:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size(), columns = grid[0].size();
        queue<pair<int, int>> cells;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 0) {
                    cells.push({i, j});
                }
            }
        }

        while (!cells.empty()) {
            int x = cells.front().first;
            int y = cells.front().second;
            cells.pop();

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newX < rows &&
                    newY >= 0 && newY < columns &&
                    grid[newX][newY] != -1 && grid[newX][newY] > 1 + grid[x][y]) {
                        grid[newX][newY] = 1 + grid[x][y];
                        cells.push({newX, newY});
                    }
            }
        }

        return;
    }
};
