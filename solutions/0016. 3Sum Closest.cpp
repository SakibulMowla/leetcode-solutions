///////////////////////////////////////////////
Time Complexity - O(N^2)
///////////////////////////////////////////////
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = numeric_limits<int>::max();
        int ans;
        for (int i = 0; i < n; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int currentDiff = abs(target - sum);
                if (currentDiff < diff) {
                    diff = currentDiff;
                    ans = sum;
                }
                if (sum > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
