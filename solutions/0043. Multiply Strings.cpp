class Solution {
public:
    vector<string> dp;

    string add(const string& num1, const string& num2) {
        int carry = 0;
        string ans;
        for (int i = 0; i < max(num1.size(), num2.size()); i++) {
            if (i < num1.size()) carry += num1[i] - '0';
            if (i < num2.size()) carry += num2[i] - '0';
            ans += (carry % 10) + '0';
            carry /= 10;
        }
        if (carry || ans == "") {
            ans += carry + '0';
        }
        return ans;
    }
    
    string multiply(const string& num, int digit) {
        if (dp[digit].size()) {
            return dp[digit];
        }
        if (digit == 0) {
            return dp[0] = "0";
        }
        int carry = 0;
        string ans;
        for (char ch: num) {
            carry += digit * (ch - '0');
            ans += (carry % 10) + '0';
            carry /= 10;
        }
        if (carry || ans == "") {
            ans += carry + '0';
        }
        return dp[digit] = ans;
    }
    
    void removeLeading(string& num) {
        while (num.size() > 1 && num[0] == '0') {
            num.erase(0, 1);
        }
        return;
    }
    
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        dp = vector<string>(10);
        
        string ans;
        string zeros;
        for (char ch: num2) {
            ans = add(ans, zeros + multiply(num1, ch - '0'));
            zeros += '0';
        }
        reverse(ans.begin(), ans.end());
        removeLeading(ans);
        return ans;
    }
};
