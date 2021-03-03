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
        int maxWordSize = 0;
        unordered_set<string> hash;
        for (string word: wordDict) {
            maxWordSize = max(maxWordSize, (int)word.size());
            hash.insert(word);
        }
        
        int n = s.size();
        vector<bool> dp(n, false);

        for (int i = 0; i < s.size(); i++) {
            if (i < maxWordSize) {
                dp[i] = hash.find(s.substr(0, i + 1)) != hash.end();
            }
            for (int j = i - 1; j >= 0 && i - j <= maxWordSize && !dp[i]; j--) {
                dp[i] = dp[j] && (hash.find(s.substr(j + 1, i - j)) != hash.end());
            }
        }
        
        return dp[n - 1];
    }
};
