// Time - O(N)
// Memory - O(N)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n);
        dp[0] = nums[0];

        if (n > 1) {
            dp[1] = max(dp[0], nums[1]);
        }

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[n - 1];
    }
};

// ------------------------------------------------------------------------

// Time - O(N)
// Memory - O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        // order is prev2, prev1, num
        int prev2 = 0;
        int prev1 = 0;
        for (int num: nums) {
            int temp = prev1;
            prev1 = max(prev1, num + prev2);
            prev2 = temp;
        }
        return prev1;
    }
};
