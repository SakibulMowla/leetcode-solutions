class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {        
        int sum = 0;
        int index = -1;
        unordered_map<int, int> sumMap;
        sumMap[sum] = index;
        
        if (k < 0) k = -k;
        bool ans = false;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k) {
                sum %= k;
            }
            if (sumMap.find(sum) != sumMap.end()) {
                if (i - sumMap[sum] > 1) {
                    ans = true;
                    break;
                }
            } else {
                sumMap[sum] = i;
            }
        }

        return ans;
    }
};
