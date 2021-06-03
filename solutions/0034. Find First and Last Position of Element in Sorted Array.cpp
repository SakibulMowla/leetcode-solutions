class Solution {
private:
    int binarySearch(vector<int>& nums, int target, bool findStarting) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (findStarting) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startIndex = binarySearch(nums, target, true);
        if (startIndex == -1) {
            return {-1, -1};
        }
        int endIndex = binarySearch(nums, target, false);
        return {startIndex, endIndex};
    }
};
