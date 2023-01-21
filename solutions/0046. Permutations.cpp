class Solution {
private:
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& permutations) {
        if (index == nums.size() - 1) {
            permutations.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            backtrack(nums, index + 1, permutations);
            swap(nums[index], nums[i]);
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        backtrack(nums, 0, permutations);
        return permutations;
    }
};
