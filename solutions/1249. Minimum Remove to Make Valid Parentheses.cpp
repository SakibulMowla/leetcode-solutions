class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        int n = s.size();
        
        vector<int> rightCount(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            rightCount[i] = rightCount[i + 1] + (int)(s[i] == ')');
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i])) {
                ans += s[i];
            } else {
                if (s[i] == '(') {
                    if (rightCount[i + 1] >= sum + 1) {
                        sum++;
                        ans += s[i];
                    }
                } else {
                    if (sum) {
                        ans += s[i];
                        sum--;
                    }
                }
            }
        }
        
        return ans;
    }
};
