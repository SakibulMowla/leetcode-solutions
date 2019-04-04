class Solution {
public:
    
    void calc(vector<vector<char>>& grid,
              vector<vector<int>>& enemy,
              int& cnt,
              int i,
              int j) {
        enemy[i][j] += cnt;
        if (grid[i][j] == 'E') cnt++;
        else if (grid[i][j] == 'W') cnt = 0;
    }
    
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int r = grid.size();
        
        if (!r) return r;
        
        int c = grid[0].size();

        vector<vector<int>> enemy(r, vector<int> (c, 0));

        for (int i = 0; i < r; i++) {
            int cnt = 0;
            for (int j = 0; j < c; j++) {
                calc(grid, enemy, cnt, i, j);
            }
            cnt = 0;
            for (int j = c - 1; j >= 0; j--) {
                calc(grid, enemy, cnt, i, j);
            }
        }    

        for (int j = 0; j < c; j++) {
            int cnt = 0;
            for (int i = 0; i < r; i++) {
                calc(grid, enemy, cnt, i, j);
            }
            cnt = 0;
            for (int i = r - 1; i >= 0; i--) {
                calc(grid, enemy, cnt, i, j);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '0') {
                    ans = max(ans, enemy[i][j]);
                }
            }
        }
        
        return ans;
    }
};
