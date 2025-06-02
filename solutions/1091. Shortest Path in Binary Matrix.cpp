class Solution {
private:
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    bool isWithinGrid(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> coords;
        if (grid[0][0] == 0) {
            coords.push({0, 0});
            grid[0][0] = 1;
        }

        while (!coords.empty()) {
            auto [x, y] = coords.front();
            coords.pop();

            if (x == n - 1 && y == n - 1) {
                return grid[x][y];
            }

            for (int k = 0; k < 8; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];
                if (isWithinGrid(newX, newY, n) && grid[newX][newY] == 0) {
                    grid[newX][newY] = 1 + grid[x][y];
                    coords.push({newX, newY});
                }
            }
        }

        return -1;
    }
};
