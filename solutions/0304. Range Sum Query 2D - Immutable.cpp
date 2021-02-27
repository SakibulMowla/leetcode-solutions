class NumMatrix {
public:
    vector<vector<int>> sum;

    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        if (!r) {
            return;
        }
        int c = matrix[0].size();
        
        sum = vector<vector<int>> (r, vector<int> (c));
        
        for (int i = 0; i < r; i++) {
            int current = 0;
            for (int j = 0; j < c; j++) {
                current += matrix[i][j];
                sum[i][j] = current + (i ? sum[i - 1][j] : 0);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = sum[row2][col2] -
                  (row1 ? sum[row1 - 1][col2] : 0) -
                  (col1 ? sum[row2][col1 - 1] : 0) +
                  (row1 && col1 ? sum[row1 - 1][col1 - 1] : 0);
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
