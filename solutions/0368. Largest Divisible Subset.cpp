class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        sort(nums.begin(), nums.end());
        
        int maxSize = 0;
        int maxSetEnd = -1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] > dp[i]) {
                    dp[i] = dp[j];
                }
            }
            dp[i]++;
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxSetEnd = i;
            }
        }
                
        int cur = nums[maxSetEnd];
        int curSize = maxSize;
        vector<int> ans;
        
        for (int i = maxSetEnd; i >= 0; i--) {
            if (cur % nums[i] == 0 && dp[i] == curSize) {
                ans.push_back(nums[i]);
                cur = nums[i];
                curSize--;
            }
        }
        
        return ans;
    }
};
