class Solution {
private:
    int solve(int left, int right, vector<int>& nums, vector<vector<int>>& dp) {
        if (left > right)
            return 0;
        
        int ret = dp[left][right];
        if (ret != -1) 
            return ret;
        
        ret = 0;
        for (int k = left; k <= right; k++) {
            // k is the last balloon to burst in range [left, right]
            ret = max(ret, nums[left - 1] * nums[k] * nums[right + 1] +
                           solve(left, k - 1, nums, dp) + solve(k + 1, right, nums, dp));
        }

        return dp[left][right] = ret;
    }

public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        return solve(1, n - 2, nums, dp);
    }
};

// Bottom-up

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int N = n + 2;
        vector<vector<int>> dp(N, vector<int> (N, 0));

        for (int len = 1; len <= n; len++) {
            for (int left = 1; left + len - 1 <= N - 2; left++) {
                int right = left + len - 1;
                // try to burst each balloon k as the last balloon in the range [left, right]
                for (int k = left; k <= right; k++) {
                    dp[left][right] = max(dp[left][right], nums[left - 1] * nums[k] * nums[right + 1] +
                                                           dp[left][k - 1] + dp[k + 1][ right]);
                }
            }
        }

        return dp[1][N - 2];
    }
};
