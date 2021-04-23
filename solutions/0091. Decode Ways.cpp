// =============================================
// Time - O(n) Memory - O(n)
// =============================================

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        s = '0' + s;
        for (int i = 1; i <= n; i++) {
            if (s[i] >= '1' && s[i] <= '9') dp[i] += dp[i - 1];
            int twoDigit = ((s[i - 1] - '0') * 10 + s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};


// =============================================
// Time - O(n) Memory - O(1)
// =============================================

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int secondLast = 0;
        int last = 1;
    
        for (int i = 0; i < n; i++) {
            int now = 0;
            
            if (s[i] != '0') {
                now += last;
            }
            
            if (i) {
                int twoDigits = stoi(s.substr(i - 1, 2));
                if (twoDigits >= 10 && twoDigits <= 26) {
                    now += secondLast;
                }
            }
            
            secondLast = last;
            last = now;
        }
        
        return last;
    }
};
