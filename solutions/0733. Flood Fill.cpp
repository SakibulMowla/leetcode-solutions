class Solution {
private:
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};

    void floodFill(vector<vector<int>>& image, int row, int column, int color, int rows, int columns) {
        int currentCol = image[row][column];
        image[row][column] = color;
        for (int i = 0; i < 4; i++) {
            int nextRow = row + dx[i];
            int nextColumn = column + dy[i];
            if (nextRow >= 0 && nextRow < rows && 
                nextColumn >= 0 && nextColumn < columns &&
                image[nextRow][nextColumn] == currentCol) {
                floodFill(image, nextRow, nextColumn, color, rows, columns);
            }
        }
        return;
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int columns = image[0].size();
        if (image[sr][sc] != color) {
            floodFill(image, sr, sc, color, rows, columns);
        }
        return image;
    }
};
