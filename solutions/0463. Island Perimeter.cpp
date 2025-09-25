// Time - O(n * m)
// Memory - O(n * m)

class Solution {
private:
    int rows, cols;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    bool isWithinGrid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& count) {
        visited[x][y] = true;

        for (int k = 0; k < 4; k++) {
            int nextX = x + dx[k];
            int nextY = y + dy[k];
            if (isWithinGrid(nextX, nextY) && grid[nextX][nextY] == 1 && !visited[nextX][nextY]) {
                dfs(grid, visited, nextX, nextY, count);
            }
            
            if (!isWithinGrid(nextX, nextY) || grid[nextX][nextY] == 0) {
                count++;
            }
        }

        return;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool> (cols, false));

        int count = 0;
        for (int i = 0; i < rows; i++) 
            for (int j = 0; j < cols; j++)
                if (grid[i][j] == 1) {
                    dfs(grid, visited, i, j, count);
                    return count;
                }    
        
        return 0;
    }
};

// ------------------------------------------------------------------------------------

// Time - O(n * m)
// Memory - O(1)

class Solution {
private:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    int rows, cols;

    inline bool isLand(vector<vector<int>>& grid, int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1;
    }

    inline int getCount(vector<vector<int>>& grid, int x, int y) {
        int count = 4;
        for (int k = 0; k < 4; k++) {
            int nextX = x + dx[k];
            int nextY = y + dy[k];
            if (isLand(grid, nextX, nextY))
                count--;
        }

        return count;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int count = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (grid[i][j] == 1) {
                    count += getCount(grid, i, j);
                }
        
        return count;
    }
};
