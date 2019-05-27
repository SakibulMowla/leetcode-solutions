class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int needed = target - nums[i];
            if (hash.find(needed) != hash.end()) {
                ans = { hash[needed], i };
                break;
            }
            hash[nums[i]] = i;
        }
        
        return ans;
    }
};
