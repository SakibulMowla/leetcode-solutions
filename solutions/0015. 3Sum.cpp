class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            int target = -nums[i];
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[j] + nums[k];

                if (sum < target) j++;
                else if (sum > target) k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                }
            }
 
            while (i + 1 < n && nums[i + 1] == nums[i]) i++;
        }

        return ans;
    }
};
