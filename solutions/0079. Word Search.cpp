class Solution {
private:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int rows;
    int cols;

    bool backtrack(int index, int x, int y, vector<vector<char>>& board, string& word) {
        if (index == word.size()) {
            return true;
        }

        if (x < 0 || x >= rows || y < 0 || y >= cols || board[x][y] != word[index]) {
            return false;
        }

        char temp = board[x][y];
        board[x][y] = '0';

        for (int k = 0; k < 4; k++) {
            int newx = x + dx[k];
            int newy = y + dy[k];
            if (backtrack(index + 1, newx, newy, board, word)) {
                return true;
            }
        }

        board[x][y] = temp;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (backtrack(0, i, j, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};
