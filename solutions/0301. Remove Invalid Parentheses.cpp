class Solution {
public:
    int solve(string& s, int pos, int sum, vector<vector<int>>& dp) {
        if (sum < 0) {
            return numeric_limits<int>::min();
        }
        if (pos == s.size()) {
            return sum == 0 ? 0 : numeric_limits<int>::min();
        } else {
            int& ret = dp[pos][sum];
            if (ret != -1) {
                return ret;
            }
            
            ret = solve(s, pos + 1, sum, dp);
            if (s[pos] != '(' && s[pos] != ')') {
                ret = max(ret, 1 + solve(s, pos + 1, sum, dp));
            } else {
                ret = max(ret, 1 + solve(s, pos + 1, sum + (s[pos] == '(' ? 1 : -1), dp));
            }
            
            return ret;
        }
    }
    
    void findPath(string& s, int pos, int sum, vector<vector<int>>& dp, string& cur, set<string>& ans) {
        if (pos == s.size()) {
            ans.insert(cur);
        } else {
            if (solve(s, pos + 1, sum, dp) == dp[pos][sum]) {
                findPath(s, pos + 1, sum, dp, cur, ans);
            }
            if (s[pos] != '(' && s[pos] != ')') {
                if (dp[pos][sum] == 1 + solve(s, pos + 1, sum, dp)) {
                    cur.push_back(s[pos]);
                    findPath(s, pos + 1, sum, dp, cur, ans);
                    cur.pop_back();
                }
            } else {
                if (dp[pos][sum] == 1 + solve(s, pos + 1, sum + (s[pos] == '(' ? 1 : -1), dp)) {
                    cur.push_back(s[pos]);
                    findPath(s, pos + 1, sum + (s[pos] == '(' ? 1 : -1), dp, cur, ans);
                    cur.pop_back();
                }
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        
        solve(s, 0, 0, dp);
        
        set<string> ans;
        string cur;
        findPath(s, 0, 0, dp, cur, ans);
        
        vector<string> ret;
        for (auto it: ans) {
            ret.push_back(it);
        }
        
        return ret;
    }
};
