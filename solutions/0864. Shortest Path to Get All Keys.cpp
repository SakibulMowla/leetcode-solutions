struct Node {
    int x, y, cost, mask;
    Node(int x, int y, int cost, int mask): x(x), y(y), cost(cost), mask(mask) {}

    bool operator < (const Node& other) const {
        return cost > other.cost;
    }
};

class Solution {
private:
    int rows, cols;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    bool isKey(char ch) {
        return ch >= 'a' && ch <= 'f';
    }

    bool isLock(char ch) {
        return ch >= 'A' && ch <= 'F';
    }

    bool isInGrid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    bool gotKeyForLock(char lock, int keyMask) {
        int bit = (lock - 'A');
        return (bool)(keyMask & (1 << bit));
    }

    int getNewMask(vector<string>& grid, Node& cur, int x, int y) {
        int newMask = cur.mask;
        if (isKey(grid[x][y])) {
            newMask |= (1 << (grid[x][y] - 'a'));
        }
        return newMask;
    }

    bool isMovePossible(vector<string>& grid, Node& cur, int x, int y,
                        vector<vector<vector<int>>>& dist) {
        if (!isInGrid(x, y) ||
            grid[x][y] == '#') {
            return false;
        }

        if (isLock(grid[x][y]) && !gotKeyForLock(grid[x][y], cur.mask)) {
            return false;
        }

        int newMask = getNewMask(grid, cur, x, y);

        return dist[x][y][newMask] > 1 + cur.cost;
    }

public:
    int shortestPathAllKeys(vector<string>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        int keys = 0;
        int startX, startY;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (isKey(grid[i][j])) {
                    keys++;
                }
                if (grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                }
            }
        }

        int lim = (1 << keys);
        vector<vector<vector<int>>> dist(rows, vector<vector<int>>(cols, vector<int>(lim, INT_MAX)));
        dist[startX][startY][0] = 0;

        priority_queue<Node> nodes;
        nodes.push(Node(startX, startY, 0, 0));

        int ans = INT_MAX;

        while (!nodes.empty()) {
            auto top = nodes.top();
            nodes.pop();

            if (top.mask == lim - 1) {
                ans = min(ans, top.cost);
                break;
            }

            for (int k = 0; k < 4; k++) {
                int newX = top.x + dx[k];
                int newY = top.y + dy[k];
                if (isMovePossible(grid, top, newX, newY, dist)) {
                    int newMask = getNewMask(grid, top, newX, newY);
                    dist[newX][newY][newMask] = 1 + top.cost;
                    nodes.push(Node(newX, newY, 1 + top.cost, newMask));
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
