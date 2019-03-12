class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> sumR(n + 1, 0);
        vector<int> bestVR(n + 1, numeric_limits<int>::min());
        vector<int> bestPR(n + 1);
        
        for (int i = n - 1; i >= 0; i--) {
            sumR[i] = sumR[i + 1] + nums[i];
            if (i + k <= n) {
                bestVR[i] = bestVR[i + 1];
                bestPR[i] = bestPR[i + 1];
                int val = sumR[i] - sumR[i + k];
                if (val >= bestVR[i]) {
                    bestVR[i] = val;
                    bestPR[i] = i;
                }
            }
        }
        
        vector<int> sumL(n, 0);
        vector<int> bestVL(n, numeric_limits<int>::min());
        vector<int> bestPL(n);
        
        int totalBest = numeric_limits<int>::min();
        vector<int> ans(3);
        
        for (int i = 0; i + 2 * k <= n; i++) {
            sumL[i] = nums[i] + (i ? sumL[i - 1]: 0);
            
            if (i >= k - 1) {
                bestVL[i] = i ? bestVL[i - 1] : numeric_limits<int>::min();
                bestPL[i] = i ? bestPL[i - 1] : 0;
                int val = sumL[i] - (i - k == -1 ? 0 : sumL[i - k]);
                if (val > bestVL[i]) {
                    bestVL[i] = val;
                    bestPL[i] = i - k + 1;
                }
            }
             
            if (i >= k) {
                int now = bestVL[i - 1] + (sumR[i] - sumR[i + k]) + bestVR[i + k];
                if (now > totalBest) {
                    totalBest = now;
                    ans[0] = bestPL[i - 1];
                    ans[1] = i;
                    ans[2] = bestPR[i + k];
                }
            }          
        }
        
        return ans;
    }
};
