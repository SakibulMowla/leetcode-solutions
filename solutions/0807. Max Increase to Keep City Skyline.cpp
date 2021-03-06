class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> rowMax(cols, 0);
        vector<int> colMax(rows, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rowMax[j] = max(rowMax[j], grid[i][j]);
                colMax[i] = max(colMax[i], grid[i][j]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans += min(rowMax[j], colMax[i]) - grid[i][j];
            }
        }
        
        return ans;
    }
};
