// ============================================================
// Time - O(n * m * log(min(n, m))) Memory - O(n * m)
// ============================================================

class Solution {
private:
    vector<vector<int>> calcCumulativeSum(int n, int m, vector<vector<int>>& matrix) {
        vector<vector<int>> sum(n + 1, vector<int> (m + 1, 0));
        for (int i = 1; i <= n; i++) {
            int running = 0;
            for (int j = 1; j <= m; j++) {
                int cur = matrix[i - 1][j - 1];
                running += cur;
                sum[i][j] = running + sum[i - 1][j];
            }
        }

        return sum;
    }

    int findSum(int x1, int y1, int x2, int y2, vector<vector<int>>& sum) {
        return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
    }

    int binarySearch(int x, int y, int len, vector<vector<int>>& sum) {
        int lo = 0;
        int hi = len;
        int maxDepth = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int expected = (mid + 1) * (mid + 1);
            int got = findSum(x, y, x + mid, y + mid, sum);

            if (expected == got) {
                maxDepth = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return maxDepth + 1;
    }
    
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> sum = calcCumulativeSum(n, m, matrix);
        
        int squares = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == 1) {
                    squares += binarySearch(i, j, min(n - i, m - j), sum);
                }
            }
        }

        return squares;
    }
};

// ============================================================
// Time - O(n * m) Memory - O(1)
// ============================================================

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int squares = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 && j > 0 && matrix[i][j] == 1) {
                    matrix[i][j] = 1 + min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));
                }
                squares += matrix[i][j];
            }
        }

        return squares;
    }
};
