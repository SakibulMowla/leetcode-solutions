// Time- O(n * 1000)
// Memory - O(n)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, n);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                dp[i + j] = min(dp[i + j], 1 + dp[i]);
            }
        }

        return dp[n - 1];
    }
};

// -------------------------------------------------

// Time- O(n)
// Memory - O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentJumpEnd = 0;
        int longest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            longest = max(longest, i + nums[i]);
            if (i == currentJumpEnd) {
                jumps++;
                currentJumpEnd = longest;
            }
        }
        
        return jumps;
    }
};
