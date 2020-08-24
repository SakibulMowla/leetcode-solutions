class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n + 1, false));
        int ansStartIndex = 0;
        int ansLength = 0;
        
        for (int length = 1; length <= n; length++) {
            for (int startIndex = 0; startIndex + length - 1 < n; startIndex++) {
                if ((s[startIndex] == s[startIndex + length - 1]) &&
                    (length < 3 ? true : isPalindrome[startIndex + 1][length - 2])) {
                    isPalindrome[startIndex][length] = true;
                    ansStartIndex = startIndex;
                    ansLength = length;
                }
            }
        }
        
        return s.substr(ansStartIndex, ansLength);
    }
};
