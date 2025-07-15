class Solution {
private:
    int rows, cols;

    bool isWithinGrid(int x, int y) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }

    struct State {
        int x;
        int y;
        int left;
    };

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<vector<int>>> dist(rows, vector<vector<int>> (cols, vector<int> (k + 1, INT_MAX)));
        dist[0][0][k] = 0;
        
        queue<State> positions;
        positions.push({0, 0, k});

        while (!positions.empty()) {
            auto [x, y, left] = positions.front();
            positions.pop();

            if (x == rows - 1 && y == cols - 1) {
                return dist[x][y][left];
            }

            for (int k = 0; k < 4; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];

                if (!isWithinGrid(newX, newY))
                    continue;

                int newLeft = left - grid[newX][newY];

                if (newLeft >= 0 &&
                    dist[newX][newY][newLeft] > 1 + dist[x][y][left]) {
                        dist[newX][newY][newLeft] = 1 + dist[x][y][left];
                        positions.push({newX, newY, newLeft});
                }
            }
        }

        return -1;
    }
};
