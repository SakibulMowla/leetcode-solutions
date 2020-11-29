=====================================================
// Recursive DP
=====================================================

class Solution {
public:
    bool solve(const string& s,
               const unordered_set<string>& hash,
               vector<int>& dp,
               int n,
               int pos) {
        if (pos == n) {
            return 1;
        }
        
        if (dp[pos] != -1) {
            return dp[pos];
        }
        
        string current;
        for (int i = pos; i < n; i++) {
            current += s[i];
            if (hash.find(current) != hash.end()) {
                if (solve(s, hash, dp, n, i + 1) == 1) {
                    return dp[pos] = 1;
                }
            }
        }
        
        return dp[pos] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        for (string& word: wordDict) {
            hash.insert(word);
        }
        
        int n = s.size();
        vector<int> dp(n, -1);
        
        return (bool)solve(s, hash, dp, n, 0);
    }
};

=====================================================
// Iterative DP
=====================================================

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size(), sz = wordDict.size();
        
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        unordered_set<string> hash;
        int mx = 0;
        
        for (int i = 0; i < sz; i++) {
            hash.insert(wordDict[i]);
            mx = max(mx, (int)wordDict[i].size());
        }
        
        for (int i = 0; i < len; i++) {
            if (dp[i]) {
                string tmp;
                for (int j = i; j < len && (j - i + 1) <= mx; j++) {
                    tmp.push_back(s[j]);
                    if (hash.find(tmp) != hash.end()) {
                        dp[j + 1] = true;
                    }
                }
            }
        }
        
        return dp[len];
    }
};
