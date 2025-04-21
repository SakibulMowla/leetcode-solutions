// Bit Masking
// Time - O(n * (2 ^ n))
// Memory - O(n * (2 ^ n))

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        int limit = (1 << n);

        sort(nums.begin(), nums.end());

        set<vector<int>> subsets;
        for (int mask = 0; mask < limit; mask++) {
            vector<int> cur;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cur.push_back(nums[i]);
                }
            }
            subsets.insert(cur);
        }

        vector<vector<int>> ans;
        for (auto it: subsets) {
            ans.push_back(it);
        }

        return ans;
    }
};

// Backtracking
// Time - O(n * (2 ^ n))
// Memory - O(n * (2 ^ n))

class Solution {
private:
    void backtrack(int index, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
        ans.push_back(cur);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            cur.push_back(nums[i]);
            backtrack(i + 1, nums, cur, ans);
            cur.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        backtrack(0, nums, cur, ans);
        return ans;
    }
};
