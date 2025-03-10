class Solution {
private: 
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
    int color = 200;

    bool isValid(int x, int y, int rows, int columns, vector<vector<int>>& matrix) {
        return x >= 0 && x < rows && y >= 0 && y < columns && matrix[x][y] != color;
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int cells = rows * columns;
        int x = 0, y = -1, dir = 0;
        vector<int> elements;

        while (cells) {
            while (isValid(x + dx[dir], y + dy[dir], rows, columns, matrix)) {
                cells--;
                x += dx[dir];
                y += dy[dir];
                elements.push_back(matrix[x][y]);
                matrix[x][y] = color;
            }
            dir = (dir + 1) % 4;
        }

        return elements;
    }
};
