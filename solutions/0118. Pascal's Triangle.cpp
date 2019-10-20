class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> nCr;
        for (int i = 0; i < numRows; i++) {
            nCr.push_back(vector<int>(i + 1));
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) nCr[i][j] = 1;
                else nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
            }
        }
        return nCr;
    }
};
