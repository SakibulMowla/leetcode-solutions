class Solution {
private:
    void backtrack(int pos, int n, int sum, string& cur, vector<string>& ans) {
        if (sum < 0 || sum > n - pos) {
            return;
        }

        if (pos == n) {
            if (sum == 0) {
                ans.push_back(cur);
            }
            return;
        }
        
        cur.push_back('(');
        backtrack(pos + 1, n, sum + 1, cur, ans);
        cur.pop_back();
        
        cur.push_back(')');
        backtrack(pos + 1, n, sum - 1, cur, ans);
        cur.pop_back();
        
        return;
    }
    
public:
    vector<string> generateParenthesis(int n) {
        string cur;
        vector<string> ans;
        
        backtrack(0, 2 * n, 0, cur, ans);
        
        return ans;
    }
};
