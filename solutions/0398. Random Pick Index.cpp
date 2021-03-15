class Solution {
public:
    unordered_map<int, vector<int>> valToIndices;

    Solution(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (valToIndices.find(nums[i]) == valToIndices.end()) {
                valToIndices[nums[i]] = vector<int> ();
            }
            valToIndices[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int ret = valToIndices[target][rand() % valToIndices[target].size()];
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
