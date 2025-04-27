// Time - O(n ^ 2)
// Memory  - O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

// ------------------------------------------

// Time - O(nlog(n))
// Memory  - O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n);
        int len = 0;

        for (int i = 0; i < n; i++) {
            int low = 0, high = len - 1, index = len;    
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[i] <= lis[mid]) {
                    index = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            lis[index] = nums[i];
            len = max(len, index + 1);
        }

        return len;
    }
};
