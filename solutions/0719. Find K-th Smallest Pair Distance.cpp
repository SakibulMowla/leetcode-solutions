class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = 1000000;
        int ans;
        int n = nums.size();
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            for (int i = 0, j = 0; i < n; i++) {
                j = max(i, j);
                while (j + 1 < n && nums[j + 1] - nums[i] <= mid) {
                    j++;
                }
                cnt += (j - i);
            }
            if (cnt >= k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
