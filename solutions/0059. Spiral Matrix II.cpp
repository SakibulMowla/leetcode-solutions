class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int cnt = 0;
        int dir = 0;
        int row = 0;
        int col = -1;

        while (cnt < n * n) {
            if (dir == 0) {
                while (col + 1 < n && ans[row][col + 1] == 0) {
                    col++;
                    ans[row][col] = ++cnt;
                }
            } else if (dir == 1) {
                while (row + 1 < n  && ans[row + 1][col] == 0) {
                    row++;
                    ans[row][col] = ++cnt;
                }
            } else if (dir == 2) {
                while (col - 1 >= 0 && ans[row][col - 1] == 0) {
                    col--;
                    ans[row][col] = ++cnt;
                }
            } else if (dir == 3) {
                while (row - 1 >= 0 && ans[row - 1][col] == 0) {
                    row--;
                    ans[row][col] = ++cnt;
                }
            }

            dir = (dir + 1) % 4;
        }
        
        return ans;
    }
};
