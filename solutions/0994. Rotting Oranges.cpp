class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) {
            return 0;
        }
        int cols = grid[0].size();
        
        int rottenCount = 0;
        int totalOrange = 0;
        
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    rottenCount++;
                    q.push({i, j});
                }
                totalOrange += (grid[i][j] == 1 || grid[i][j] == 2);
            }
        }
        
        int ans = 0;
        vector<vector<int>> timeCount(rows, vector<int>(cols, 0));
        
        vector<int> dx{-1, 1, 0, 0};
        vector<int> dy{0, 0, -1, 1};

        while (!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();
            
            pair<int, int> step;
            for (int k = 0; k < 4; k++) {
                step.first = front.first + dx[k];
                step.second = front.second + dy[k];
                if (step.first >= 0 && step.first < rows && step.second >= 0 && step.second < cols && grid[step.first][step.second] == 1 && timeCount[step.first][step.second] == 0) {
                    timeCount[step.first][step.second] = timeCount[front.first][front.second] + 1;
                    ans = max(ans, timeCount[step.first][step.second]);
                    q.push(step);
                    rottenCount++;
                }
            }
        }
        
        return rottenCount == totalOrange ? ans : -1;
    }
};
