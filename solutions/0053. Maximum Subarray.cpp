class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = 0;
        for (int num: nums) {
            currentSum += num;
            currentSum = max(num, currentSum);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
