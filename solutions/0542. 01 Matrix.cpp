class Solution {
private:
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<vector<int>> dist(rows, vector<int> (cols, -1));
        queue<pair<int, int>> cells;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    cells.push({i, j});
                }
            }
        }   

        while (!cells.empty()) {
            auto cell = cells.front();
            cells.pop();
            for (int i = 0; i < 4; i++) {
                int x = cell.first + dx[i];
                int y = cell.second + dy[i];
                if (x >= 0 && x < rows && y >= 0 && y < cols && dist[x][y] == -1) {
                    dist[x][y] = dist[cell.first][cell.second] + 1;
                    cells.push({x, y});
                }
            }
        }

        return dist;
    }
};
