class Solution {
public:
    
    void backtrack(int pos, int n, vector<int>& nums, vector<vector<int>>& ans) {
        if (pos == n - 1) {
            ans.push_back(nums);
        } else {
            backtrack(pos + 1, n, nums, ans);
            for (int i = pos + 1; i < n; i++) {
                swap(nums[pos], nums[i]);
                backtrack(pos + 1, n, nums, ans);
                swap(nums[pos], nums[i]);
            }
        }
        
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        if (n == 0) {
            return ans;
        }

        sort(nums.begin(), nums.end());
        backtrack(0, n, nums, ans);

        return ans;
    }
};
