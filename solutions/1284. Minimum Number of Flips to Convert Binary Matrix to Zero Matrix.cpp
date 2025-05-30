class Solution {
private:
    int rows, cols;

    vector<int> dx = {0, -1, 1, 0, 0};
    vector<int> dy = {0, 0, 0, -1, 1};

    bool isWithinMat(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    int matToMask(vector<vector<int>>& mat) {
        int mask = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j]) {
                    mask |= (1 << (i * cols + j));
                }
            }
        }
        return mask;
    }

    vector<vector<int>> maskToMat(int mask) {
        vector<vector<int>> mat(rows, vector<int> (cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = (bool)(mask & (1 << (i * cols + j)));
            }
        }
        return mat;
    }

    void printMat(vector<vector<int>>& mat) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << ",";
            }
            cout << endl;
        }
    }

    void flip(vector<vector<int>>& mat, int i, int j) {
        for (int k = 0; k < 5; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (!isWithinMat(x, y)) {
                continue;
            }
            mat[x][y] = !mat[x][y];
        }
    }

public:
    int minFlips(vector<vector<int>>& mat) {
        rows = mat.size();
        cols = mat[0].size();

        int lim = (1 << (rows * cols));
        vector<int> dist(lim, INT_MAX);
        queue<int> nodes;

        int startMask = matToMask(mat);
        nodes.push(startMask);
        dist[startMask] = 0;

        while (!nodes.empty()) {
            int cur = nodes.front();
            nodes.pop();

            if (cur == 0) {
                return dist[cur];
            }

            vector<vector<int>> curMat = maskToMat(cur);

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    vector<vector<int>> curMatCopy = curMat;
                    flip(curMatCopy, i, j);
                    int nextMask = matToMask(curMatCopy);
                    if (dist[nextMask] > 1 + dist[cur]) {
                        dist[nextMask] = 1 + dist[cur];
                        nodes.push(nextMask);
                    }
                }
            }
        }

        return -1;
    }
};
