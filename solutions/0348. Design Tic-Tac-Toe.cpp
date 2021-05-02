class TicTacToe {
private:
    int n;
    vector<vector<int>> rowCount;
    vector<vector<int>> colCount;
    vector<vector<int>> diagCount;
    bool isGameOver;
    int winner;
    
    bool isDiag1(int row, int col) {
        return row == col;
    }
    
    bool isDiag2(int row, int col) {
        return col == n - row - 1;
    }

public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        isGameOver = false;
        winner = 0;
        rowCount = vector<vector<int>>(2, vector<int>(n, 0));
        colCount = vector<vector<int>>(2, vector<int>(n, 0));
        diagCount = vector<vector<int>>(2, vector<int>(2, 0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (isGameOver) {
            return winner;
        }

        rowCount[player - 1][row]++;
        colCount[player - 1][col]++;
        if (isDiag1(row, col)) diagCount[player - 1][0]++;
        if (isDiag2(row, col)) diagCount[player - 1][1]++;
        
        if (rowCount[player - 1][row] == n ||
            colCount[player - 1][col] == n ||
            diagCount[player - 1][0] == n ||
            diagCount[player - 1][1] == n) {
            winner = player;
            isGameOver = true;
        }
        
        return winner;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
