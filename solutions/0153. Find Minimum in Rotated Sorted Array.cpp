class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int lo = 0, hi = len - 1;
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= nums[len - 1]) {
                hi = mid - 1;
                ans = nums[mid];
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
