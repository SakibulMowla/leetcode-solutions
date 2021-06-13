class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n + 1, numeric_limits<int>::max());
        
        int lisLen = 0;
        for (int i = 0; i < n; i++) {
            int lo = 0;
            int hi = lisLen;
            int index;
            
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[i] <= lis[mid]) {
                    index = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            
            lis[index] = nums[i];
            lisLen = max(lisLen, index + 1);
        }
        
        return lisLen;
    }
};
