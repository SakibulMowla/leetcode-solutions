class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1;
        
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (firstIndex.find(sum - k) != firstIndex.end()) {
                ans = max(ans, i - firstIndex[sum - k]);
            }
            if (firstIndex.find(sum) == firstIndex.end()) {
                firstIndex[sum] = i;
            }
        }
        
        return ans;
    }
};
