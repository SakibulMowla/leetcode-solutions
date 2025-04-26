// Time - O(n^2)
// Memory - O(n^2)

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));

        int ans = 0;
        for (int len = 1; len <= n; len++) {
            for (int start = 0; start + len <= n; start++) {
                int end = start + len - 1;
                dp[start][end] = (s[start] == s[end]) && 
                                 (len <= 3 || dp[start + 1][end - 1]);
                ans += (int)dp[start][end];
            }
        }

        return ans;
    }
};

// ---------------------------------------------------------------

// Time - O(n^2)
// Memory - O(1)

class Solution {
private:
    int substringsFrom(string& s, int start, int end) {
        int n = s.size(), count = 0;
        while (start >= 0 && end < n && s[start] == s[end]) {
            count++;
            start--;
            end++;
        }

        return count;
    }

public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += substringsFrom(s, i, i);
            ans += substringsFrom(s, i, i + 1);
        }

        return ans;
    }
};
