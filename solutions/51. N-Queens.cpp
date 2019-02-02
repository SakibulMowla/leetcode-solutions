class Solution {
public:
    void bctk(
        int n,
        int row,
        vector<pair<int, int>>& current,
        vector<vector<string>>& ans
    ) {
        if (0 == row) {
            vector<string> board(n, string(n, '.'));
            for (auto queen: current) {
                board[queen.first - 1][queen.second - 1] = 'Q';
            }
            ans.push_back(board);
        } else {
            for (int col = 1; col <= n; col++) {
                bool flag = true;
                for (auto queen: current) {
                    if (queen.second == col ||
                       abs(queen.first - row) == abs(queen.second - col)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    current.push_back({row, col});
                    bctk(n, row - 1, current, ans);
                    current.pop_back();
                }
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<pair<int, int>> current;
        bctk(n, n, current, ans);
        return ans;
    }
};
