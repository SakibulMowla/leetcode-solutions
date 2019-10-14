class Solution {
public:
    
    bool isPerfectSqr(int n) {
        double root = sqrt(n);
        return root == (int)root;
    }
    
    int solve(int pos,
              int& n,
              int mask,
              int last,
              vector<int>& A,
              vector<vector<int>>& dp) {
        if (pos == -1) {
            return 1;
        } else if (dp[mask][last] != -1) {
            return dp[mask][last];
        } else {
            dp[mask][last] = 0;
            for (int i = 0; i < n; i++) if ((mask >> i) & 1) {
                if (last == n || isPerfectSqr(A[i] + A[last])) {
                    int newMask = (mask & ~(1 << i));
                    dp[mask][last] += solve(pos - 1, n, newMask, i, A, dp);
                }
            }
            return dp[mask][last];
        }
    }

    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        int lim = (1 << n);
        vector<vector<int>> dp(lim, vector<int> (n + 1, -1));
        int res = solve(n - 1, n, lim - 1, n, A, dp);
        
        vector<int> fact(13, 1);
        for (int i = 1; i < 13; i++) {
            fact[i] = i * fact[i - 1];
        }
        
        sort(A.begin(), A.end());
        int last = -1;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] != A[i - 1]) {
                res /= fact[cnt];
                cnt = 1;
            } else {
                cnt++;
            }
        }
        res /= fact[cnt];
        
        return res;
    }
};
