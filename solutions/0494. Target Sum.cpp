// Recursive DP
// Time - O(n * m)
// Memory - O(n * m)

class Solution {
private:
    int solve(int index, int sum, vector<int>& nums, vector<unordered_map<int, int>>& dp) {
        if (index == -1) {
            return (int)(sum == 0);
        }

        if (dp[index].find(sum) != dp[index].end()) {
            return dp[index][sum];
        }

        int ret = solve(index - 1, sum + nums[index], nums, dp) +
                  solve(index - 1, sum - nums[index], nums, dp);

        return dp[index][sum] = ret;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);

        return solve(n - 1, target, nums, dp);
    }
};

// ----------------------------------------------------------------

// Meet in the middle
// Time - O(2 ^ (n / 2)) * O(n / 2)
// Memory - O(2 ^ (n / 2))

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int n1 = n / 2, n2 = n - n1;

        int lim = (1 << n1);
        unordered_map<int, int> combinations;

        for (int mask = 0; mask < lim; mask++) {
            int sum = 0;
            for (int i = 0; i < n1; i++) {
                sum += (mask & (1 << i)) ? nums[i] : -nums[i];
            }
            combinations[sum]++;
        }

        int ans = 0;
        lim = (1 << n2);
        
        for (int mask = 0; mask < lim; mask++) {
            int sum = 0;
            for (int i = 0; i < n2; i++) {
                sum += (mask & (1 << i)) ? nums[n1 + i] : -nums[n1 + i];
            }
            ans += combinations[target - sum];
        }

        return ans;
    }
};

// ----------------------------------------------------------------

// Time - O(n * m)
// Memory - O(m)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> nextDp;
            for (auto it: dp) {
                nextDp[it.first + nums[i]] += it.second;
                nextDp[it.first - nums[i]] += it.second;
            }
            dp = nextDp;
        }

        return dp[target];
    }
};

// ----------------------------------------------------------------

// Time - O(n * m)
// Memory - O(m)
// Explanation: https://leetcode.com/problems/target-sum/solutions/97334/java-15-ms-c-3-ms-o-ns-iterative-dp-solution-using-subset-sum-with-explanation/

class Solution {
private:
    int findSubsets(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int num: nums) {
            for (int i = target; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }

        return dp[target];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }

        int positiveSumX2 = sum + target;

        if (sum < target || positiveSumX2 % 2 == 1 || positiveSumX2 < 0) {
            return 0;
        }

        return findSubsets(nums, positiveSumX2 / 2);
    }
};
