class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxRange = 0;
        for (int i = 0; i < n; i++) {
            if (maxRange < i) {
                return false;
            }
            maxRange = max(maxRange, i + nums[i]);
        }
        return true;
    }
};
