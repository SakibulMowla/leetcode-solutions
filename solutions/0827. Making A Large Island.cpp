class Solution {
private:
    int n, component;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> gridToComponent;
    unordered_map<int, int> componentToSize;

    bool isWithinGrid(int newX, int newY) {
        return newX >= 0 && newX < n && newY >= 0 && newY < n;
    }

    void traverse(int x, int y, vector<vector<int>>& grid, int& componentSize) {
        gridToComponent[x][y] = component;
        componentSize++;
        for (int k = 0; k < 4; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if (isWithinGrid(newX, newY) && 
                grid[newX][newY] == 1 &&
                gridToComponent[newX][newY] == 0) {
                traverse(newX, newY, grid, componentSize);
            }
        }
        return;
    }

    int findBestAnswer(int x, int y, vector<vector<int>>& grid) {
        if (grid[x][y] == 1) {
            int component = gridToComponent[x][y];
            return componentToSize[component];
        }

        int area = 1;
        unordered_set<int> seen;

        for (int k = 0; k < 4; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if (isWithinGrid(newX, newY) &&
                grid[newX][newY] == 1) {
                int component = gridToComponent[newX][newY];
                if (seen.find(component) == seen.end()) {
                    area += componentToSize[component];
                    seen.insert(component);
                }
            }
        }

        return area;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        gridToComponent = vector<vector<int>>(n, vector<int>(n, 0));

        component = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && gridToComponent[i][j] == 0) {
                    component++;
                    int componentSize = 0;
                    traverse(i, j, grid, componentSize);
                    componentToSize[component] = componentSize;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, findBestAnswer(i, j, grid));
            }
        }

        return ans;
    }
};
