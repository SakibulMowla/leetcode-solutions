class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool findLo = true) {
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (findLo) {
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
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int> { binarySearch(nums, target), binarySearch(nums, target, false) }; 
    }
};
