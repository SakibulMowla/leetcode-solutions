class Solution {
public:
    vector<int> dx = { -1, 1, 0, 0 };
    vector<int> dy = { 0, 0, -1, 1 };

    void dfs(int x, int y, vector<vector<char>>& grid, int r, int c) {
        grid[x][y] = '2';
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < r && newY >= 0 && newY < c && grid[newX][newY] == '1') {
                dfs(newX, newY, grid, r, c);
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid, r, c);
                }
            }
        }
        return ans;
    }
};
