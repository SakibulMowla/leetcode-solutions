class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int aLen = a.size();
        int bLen = b.size();
        
        int carry = 0;
        string ans;
        for (int i = 0; i < max(aLen, bLen); i++) {
            if (i < aLen) {
                carry += a[i] - '0';
            }
            if (i < bLen) {
                carry += b[i] - '0';
            }
            ans += (carry % 2) + '0';
            carry /= 2;
        }
        
        if (carry) {
            ans += (carry % 2) + '0';
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
