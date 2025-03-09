// Recursive DP
// Time  - O (n * m)
// Space  - O (n * m)

class Solution {
private:
    int solve(vector<int>& nums, vector<vector<int>>& dp, int index, int sum) {
        if (sum == 0) {
            return 1;
        }

        if (index == -1 || sum < 0) {
            return 0;
        }

        if (dp[index][sum] == -1) {
            dp[index][sum] = max(solve(nums, dp, index - 1, sum),
                                 solve(nums, dp, index - 1, sum - nums[index]));
        }

        return dp[index][sum];
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }    

        if (sum % 2 == 1) {
            return false;
        }

        vector<vector<int>> dp(nums.size(), vector<int> (sum / 2 + 1, -1));

        return solve(nums, dp, nums.size() - 1, sum / 2) == 1;
    }
};

// ----------------------------------------------
// Iterative
// Time  - O (n * m)
// Space  - O (m)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }    

        if (sum % 2 == 1) {
            return false;
        }

        vector<bool> dp(sum / 2 + 1, false);
        dp[0] = true;

        for (int num: nums) {
            // Need to iterate from right to left to make sure
            // same number isn't used more than once
            for (int j = sum / 2; j - num >= 0; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[sum / 2];
    }
};
