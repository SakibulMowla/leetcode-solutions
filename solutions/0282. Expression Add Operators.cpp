class Solution {
private:
    using ll = long long;
    vector<string> ans;
    int n;
    int target;
    string num;

    void backtrack(int index, ll prev, ll cur, ll val, vector<string>& entries) {
        if (index == n) {
            if (val == target && cur == 0) {
                string equation;
                for (int i = 1; i < entries.size(); i++) {
                    equation += entries[i];
                }
                ans.push_back(equation);
            }
            return;
        }
        
        cur = cur * 10 + (num[index] - '0');
        string curString = to_string(cur);
        
        if (cur > 0) {
            backtrack(index + 1, prev, cur, val, entries);
        }
        
        entries.push_back("+");
        entries.push_back(curString);
        backtrack(index + 1, cur, 0, val + cur, entries);
        entries.pop_back();
        entries.pop_back();
        
        if (entries.size() > 0) {
            entries.push_back("-");
            entries.push_back(curString);
            backtrack(index + 1, -cur, 0, val - cur, entries);
            entries.pop_back();
            entries.pop_back();
            
            entries.push_back("*");
            entries.push_back(curString);
            backtrack(index + 1, cur * prev, 0, val - prev + (cur * prev), entries);
            entries.pop_back();
            entries.pop_back();
        }
        
        return;
    }
    
public:
    vector<string> addOperators(string num, int target) {
        if (num.size() == 0) {
            return ans;
        }
    
        n = num.size();
        this->target = target;
        this->num = num;
        vector<string> entries;
        backtrack(0, 0, 0, 0, entries);
        return ans;
    }
};
