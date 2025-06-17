class Solution {
private: 
    vector<int> dx = {-1, 0, 1, -1, 1, -1, 0, 1};
    vector<int> dy = {-1, -1, -1, 0, 0, 1, 1, 1};

    bool isWithinBoard(int x, int y, int rows, int cols) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int alives = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    // check if the 1st bit is set
                    if (isWithinBoard(x, y, rows, cols) && (board[x][y] & 1)) {
                        alives++;
                    }
                }

                // live cell with 2, 3 live neighbors or
                // dead cell with 3 live neighbors
                bool liveInNext = ((board[i][j] & 1) && alives >= 2 && alives <= 3) ||
                                  ((board[i][j] & 1) == 0 && alives == 3);
                
                // set the second bit
                if (liveInNext) {
                    board[i][j] |= 2;
                }
            }
        }

        for (int i = 0; i < rows; i++) 
            for (int j = 0; j < cols; j++) 
                board[i][j] >>= 1;
        
        return;
    }
};
