// Time - O(N)
// Memory - O(1)

class Solution {
private: 
    int solve(vector<int>& nums, int start, int end) {
        // order is prev2, prev1, num
        int prev2 = 0;
        int prev1 = 0;
        for (int i = start; i <= end; i++) {
            int temp = prev1;
            prev1 = max(prev1, nums[i] + prev2);
            prev2 = temp;
        }
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};
