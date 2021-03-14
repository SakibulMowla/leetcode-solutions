class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int carry = 0;
        string ans;

        for (int i = 0; i < max(len1, len2); i++) {
            if (i < len1) {
                carry += num1[i] - '0';
            }
            if (i < len2) {
                carry += num2[i] - '0';
            }
            ans.push_back(carry % 10 + '0');
            carry /= 10;
        }
        
        if (carry) {
            ans.push_back(carry + '0');
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
