class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        vector<int> ans(n + 1);
        
        for (int i = n - 1; i >= 0; i--) {
            int now = digits[i] + carry;
            ans[i + 1] = now % 10;
            carry = now / 10;
        }
        
        if (carry) {
            ans[0] = carry;
        } else {
            ans.erase(ans.begin());
        }

        return ans;
    }
};
