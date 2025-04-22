class Solution {
private:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    int dfs(int x, int y, vector<vector<int>>& grid, int rows, int columns) {
        if (x >= rows || x < 0 || y >= columns || y < 0 || grid[x][y] != 1) {
            return 0;
        }

        grid[x][y] = 2;
        int area = 1;

        for (int k = 0; k < 4; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];
            area += dfs(newX, newY, grid, rows, columns);
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), columns = grid[0].size();
        int maxArea = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                maxArea = max(maxArea, dfs(i, j, grid, rows, columns));
            }
        }
        
        return maxArea;
    }
};
