class Solution {
public:
    
    void backtrack(int pos, unordered_map<int, int>& freq, vector<int>& cur, vector<vector<int>>& ans) {
        if (pos == 0) {
            ans.push_back(cur);
        } else {
            for (auto& it: freq) {
                if (it.second != 0) {
                    it.second--;
                    cur.push_back(it.first);
                    backtrack(pos - 1, freq, cur, ans);
                    cur.pop_back();
                    it.second++;
                }
            }
        }
        
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        if (n == 0) {
            return ans;
        }

        unordered_map<int, int> freq;
        for (int num: nums) {
            if (freq.find(num) == freq.end()) {
                freq[num] = 0;
            }
            freq[num]++;
        }
    
        vector<int> cur;
        backtrack(n, freq, cur, ans);
 
        return ans;
    }
};
