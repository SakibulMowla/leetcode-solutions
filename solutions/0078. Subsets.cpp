// Backtrack

class Solution {
private:
    void backtrack(int index, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
        if (index == -1) {
            ans.push_back(cur);
            return;
        }

        backtrack(index - 1, nums, cur, ans);

        cur.push_back(nums[index]);
        backtrack(index - 1, nums, cur, ans);
        cur.pop_back();

        return;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        backtrack(nums.size() - 1, nums, cur, ans);
        return ans;
    }
};

//--------------------------------------------------------------------------------

// Bit Manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int limit = (1 << n);
        vector<vector<int>> ans(limit);

        for (int cur = 0; cur < limit; cur++) {
            for (int i = 0; i < n; i++) {
                if (cur & (1 << i)) {
                    ans[cur].push_back(nums[i]);
                }
            }
        }
        
        return ans;
    }
};
