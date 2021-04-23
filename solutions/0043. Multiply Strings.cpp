class Solution {
private:
    string add(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int carry = 0;
        string ans;
        for (int i = 0; i < max(len1, len2); i++) {
            carry += (i < len1) ? num1[i] - '0' : 0;
            carry += (i < len2) ? num2[i] - '0' : 0;
            ans += (char)((carry % 10) + '0');
            carry /= 10;
        }
        if (carry) {
            ans += (char)(carry + '0');
        }
        return ans;
    }
    
    string multiply(string num, int digit) {
        string ans;
        int carry = 0;
        for (int i = 0; i < num.size(); i++) {
            carry += (num[i] - '0') * digit;
            ans += (char)((carry % 10) + '0');
            carry /= 10;
        }
        if (carry) {
            ans += (char)(carry + '0');
        }
        return ans;
    }
    
    void removeLeadingZeros(string& num) {
        while (num.size() > 1 && num[0] == '0') {
            num.erase(0, 1);
        }
        return;
    }

public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        vector<string> dp(10);
        for (int i = 0; i < 10; i++) {
            dp[i] = multiply(num2, i);
        }
        
        string ans = "0";
        for (int i = 0; i < num1.size(); i++) {
            string now = string(i, '0') + dp[num1[i] - '0'];
            ans = add(ans, now);
        }
        
        reverse(ans.begin(), ans.end());
        removeLeadingZeros(ans);
        
        return ans;
    }
};
