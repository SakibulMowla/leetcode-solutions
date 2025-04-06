// Time - O (n * m)
// Memory - O (1)

class Solution {
private:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    pair<int, int> findNextXY(int x, int y, int xMin, int xMax, int yMin, int yMax, int& dir, int len) {
        int left = len;
        while (left > 0) {
            x += dx[dir] * left;
            y += dy[dir] * left;
            if (x > xMax) {
                left = x - xMax;
                x = xMax;
            } else if (x < xMin) {
                left = xMin - x;
                x = xMin;
            } else if (y > yMax) {
                left = y - yMax;
                y = yMax;
            } else if (y < yMin) {
                left = yMin - y;
                y = yMin;
            } else {
                dir--;
                left = 0;
            }
            dir = (dir + 1) % 4;
        }

        return {x, y};
    }

public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int row = 0; row < n / 2; row++) {
            int newN = n - (2 * row);
            int len = newN - 1;
            int xMin = row, xMax = row + len;
            int yMin = row, yMax = row + len;
            for (int j = 0; j < newN - 1; j++) {
                int x = row;
                int y = row + j;
                int val = matrix[x][y];
                int dir = 0;
                for (int k = 0; k < 4; k++) {
                    pair<int, int> nextXY = findNextXY(x, y, xMin, xMax, yMin, yMax, dir, len);
                    int newX = nextXY.first, newY = nextXY.second;
                    int temp = matrix[newX][newY];
                    matrix[newX][newY] = val;
                    val = temp;
                    x = newX;
                    y = newY;
                }
            }
        }

        return;
    }
};

// ------------------------------------------------------------------

// Time - O (n * m)
// Memory - O (1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j <= i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < rows; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        return;
    }
};
