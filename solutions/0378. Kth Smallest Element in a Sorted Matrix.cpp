// =====================================================================
// ==================== Time - O(nlog(max - min)) ======================
// =====================================================================

class Solution {
private:
    int binarySearch(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int cnt = 0;
        int index = n;

        for (int i = 0; i < n; i++) {
            while (index - 1 >= 0 && matrix[i][index - 1] > mid) {
                index--;
            }           
            cnt += index;
        }
        
        return cnt;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0];
        int hi = matrix[n - 1][n - 1];
        int ans;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (binarySearch(matrix, mid) >= k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
