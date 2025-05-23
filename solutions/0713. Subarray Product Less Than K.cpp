class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int l = 0, r = 0, mul = 1; r < n; r++) {
            mul *= nums[r];
            while (mul >= k && l <= r) {
                mul /= nums[l++];
            }
            count += (r - l + 1);
        }
        
        return count;
    }
};
