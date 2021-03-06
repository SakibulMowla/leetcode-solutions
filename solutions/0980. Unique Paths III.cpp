class Solution {
public:
    using pii = pair<int, int>;
    using vi = vector<int>;
    using vii = vector<vi>;
    using viii = vector<vii>;

    int rows;
    int cols;
    int validCells;
    viii dp;

    int piiToNum(pii point) {
        return point.first * cols + point.second;
    }
    
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    int solve(pii now, pii target, int mask, vector<vector<int>>& grid) {
        if (now == target) {
            return validCells == __builtin_popcount(mask);
        }
        int& ret = dp[now.first][now.second][mask];
        if (ret != -1) {
            return ret;
        }
        
        ret = 0;
        for (int k = 0; k < 4; k++) {
            pii nxt = {now.first + dx[k], now.second + dy[k]};
            if (nxt.first >= 0 && nxt.first < rows && nxt.second >= 0 && nxt.second < cols && grid[nxt.first][nxt.second] != -1) {
                int bit = piiToNum(nxt);
                if (!(mask & (1 << bit)) && grid[nxt.first][nxt.second] != -1) {
                    ret += solve(nxt, target, mask | (1 << bit), grid);
                }   
            }
        }
        
        return ret;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        int obstacles = 0;
        pii start, target;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == -1) {
                    obstacles++;
                } else if (grid[i][j] == 1) {
                    start = {i, j};
                } else if (grid[i][j] == 2) {
                    target = {i, j};
                }
            }
        }
        
        validCells = rows * cols - obstacles;
        dp = viii(rows, vii(cols, vi(1 << (rows * cols), -1)));
        
        return solve(start, target, 1 << piiToNum(start), grid);
    }
};
