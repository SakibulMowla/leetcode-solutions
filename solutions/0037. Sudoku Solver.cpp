class Solution {
private:
    int n = 3, N = 9;
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<vector<vector<int>>> boxes;
    bool isSolved;

    void add(vector<vector<char>>& board, int x, int y, int val) {
        board[x][y] = val + '0';
        rows[x][val]++;
        cols[y][val]++;
        boxes[x / n][y / n][val]++;
    }

    void remove(vector<vector<char>>& board, int x, int y, int val) {
        board[x][y] = '.';
        rows[x][val]--;
        cols[y][val]--;
        boxes[x / n][y / n][val]--;
    }

    void findNextCell(int x, int y, vector<vector<char>>& board) {
        if (x == N - 1 && y == N - 1) {
            isSolved = true;
            return;
        }

        if (y == N - 1) {
            backtrack(x + 1, 0, board);
        } else {
            backtrack(x, y + 1, board);
        }
    }

    bool isPossible(int x, int y, int val) {
        return rows[x][val] == 0 &&
               cols[y][val] == 0 &&
               boxes[x / n][y / n][val] == 0;
    }

    void backtrack(int x, int y, vector<vector<char>>& board) {
        if (board[x][y] != '.') {
            return findNextCell(x, y, board);
        }

        for (int i = 1; i <= N; i++) {
            if (!isPossible(x, y, i)) {
                continue;;
            }

            add(board, x, y, i);
            findNextCell(x, y, board);

            if (isSolved) {
                return;
            }

            remove(board, x, y, i);
        }

        return;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<vector<int>>(N, vector<int>(N + 1, 0));
        cols = vector<vector<int>>(N, vector<int>(N + 1, 0));
        boxes = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int> (N + 1, 0)));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    add(board, i, j, board[i][j] - '0');
                }
            }
        }

        isSolved = false;
        backtrack(0, 0, board);

        return;
    }
};

// ------------------------------------------------------------------------------

class Solution {
private:
    int n = 3, N = 9;
    vector<int> rows;
    vector<int> cols;
    vector<vector<int>> boxes;
    bool isSolved;

    void add(vector<vector<char>>& board, int x, int y, int val) {
        board[x][y] = val + '0';
        rows[x] |= (1 << val);
        cols[y] |= (1 << val);
        boxes[x / n][y / n] |= (1 << val);
    }

    void remove(vector<vector<char>>& board, int x, int y, int val) {
        board[x][y] = '.';
        rows[x] &= ~(1 << val);
        cols[y] &= ~(1 << val);
        boxes[x / n][y / n] &= ~(1 << val);
    }

    void findNextCell(int x, int y, vector<vector<char>>& board) {
        if (x == N - 1 && y == N - 1) {
            isSolved = true;
            return;
        }

        if (y == N - 1) {
            backtrack(x + 1, 0, board);
        } else {
            backtrack(x, y + 1, board);
        }
    }

    bool isPossible(int x, int y, int val) {
        return (rows[x] & (1 << val)) == 0 &&
               (cols[y] & (1 << val)) == 0 &&
               (boxes[x / n][y / n] & (1 << val)) == 0;
    }

    void backtrack(int x, int y, vector<vector<char>>& board) {
        if (board[x][y] != '.') {
            return findNextCell(x, y, board);
        }

        for (int i = 1; i <= N; i++) {
            if (!isPossible(x, y, i)) {
                continue;;
            }

            add(board, x, y, i);
            findNextCell(x, y, board);

            if (isSolved) {
                return;
            }

            remove(board, x, y, i);
        }

        return;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<int>(N, 0);
        cols = vector<int>(N, 0);
        boxes = vector<vector<int>>(n, vector<int> (n, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    add(board, i, j, board[i][j] - '0');
                }
            }
        }

        isSolved = false;
        backtrack(0, 0, board);

        return;
    }
};
