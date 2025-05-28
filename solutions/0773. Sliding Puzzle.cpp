class Solution {
private:
    int rows = 2;
    int cols = 3;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    pair<int, int> findEmptySquare(vector<vector<int>>& board) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 0) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    bool isInGrid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    bool isFinalState(string& state) {
        return state == "123450";
    }

    string boardToState(vector<vector<int>>& board) {
        string state = "";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                state += to_string(board[i][j]);
            }
        }
        return state;
    }

    vector<vector<int>> stateToBoard(string& state) {
        vector<vector<int>> board(2, vector<int> (3));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i][j] = state[i * cols + j] - '0';
            }
        }
        return board;
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string, int> dist;
        queue<string> nodes;

        string starttingState = boardToState(board);

        dist[starttingState] = 0;
        nodes.push(starttingState);

        while (!nodes.empty()) {
            auto state = nodes.front();
            nodes.pop();

            if (isFinalState(state)) {
                return dist[state];
            }

            vector<vector<int>> cur = stateToBoard(state);

            auto [x, y] = findEmptySquare(cur);
            for (int k = 0; k < 4; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];

                if (!isInGrid(newX, newY)) {
                    continue;
                }

                auto next = cur;
                swap(next[x][y], next[newX][newY]);

                auto nextState = boardToState(next);

                if (dist.find(nextState) == dist.end()) {
                    dist[nextState] = dist[state] + 1;
                    nodes.push(nextState);
                }
            }
        }

        return -1;
    }
};
