class Solution {
public:    
    int n;
    vector<int> positions;
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;
    vector<vector<string>> ans;

    void addSolution(vector<int>& positions) {
        vector<string> now(n);
        for (int i = 0; i < n; i++) {
            now[i] = string(n, '.');
            now[i][positions[i]] = 'Q';
        }
        ans.push_back(now);
        return;
    }
    
    bool doesNotAttack(int i, int row) {
        return !col[i] && !diag1[row - i + 2 * n] && !diag2[row + i];
    }
    
    void addQueen(int row, int i) {
        col[i] = true;
        diag1[row - i + 2 * n] = true;
        diag2[row + i] = true;
        positions[row] = i;
    }
    
    void removeQueen(int row, int i) {
        col[i] = false;
        diag1[row - i + 2 * n] = false;
        diag2[row + i] = false;
    }

    void backtrack(int row) {
        if (row == -1) {
            addSolution(positions);
        } else {
            for (int i = 0; i < n; i++) {
                if (doesNotAttack(i, row)) {
                    addQueen(row, i);
                    backtrack(row - 1);
                    removeQueen(row, i);
                }
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        positions = vector<int>(n);
        col = vector<bool> (n, false);
        diag1 = vector<bool> (3 * n + 1, false);
        diag2 = vector<bool> (2 * n + 1, false);
        ans.clear();
        backtrack(n - 1);
        return ans;
    }
};
