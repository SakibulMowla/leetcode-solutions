class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    bool dfs(int x, int y, int pos, string& word, int rows, int cols, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if (pos + 1 == word.size()) {
            return true;
        }
        
        bool flag = false;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && board[nx][ny] == word[pos + 1] && !visited[nx][ny]) {
                visited[x][y] = true;
                flag = dfs(nx, ny, pos + 1, word, rows, cols, board, visited);
                visited[x][y] = false;
                if (flag) {
                    break;
                }
            }
        }
        
        return flag;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<pair<int, int>>> charToCord(26);
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                charToCord[board[i][j] - 'a'].push_back({i, j});
            }
        }
        
        vector<string> ans;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (string word: words) {
            bool flag = false;
            for (auto it: charToCord[word[0] - 'a']) {
                visited[it.first][it.second] = true;
                flag = dfs(it.first, it.second, 0, word, rows, cols, board, visited);
                visited[it.first][it.second] = false;
                if (flag) {
                    break;
                }
            }
            if (flag) {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};
