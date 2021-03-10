class Solution {
public:

    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        
        while (l < r) {
            while (l < r && !(isalpha(s[l]) || isdigit(s[l]))) {
                l++;
            }
            while (l < r && !(isalpha(s[r]) || isdigit(s[r]))) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
        
        return true;
    }
};
