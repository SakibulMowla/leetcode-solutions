class Solution {
private:
    bool isValidChar(char ch) {
        return isalpha(ch) || isdigit(ch);
    }

public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        
        while (l < r) {
            if (!isValidChar(s[l])) {
                l++;
            } else if (!isValidChar(s[r])) {
                r--;
            } else {
                if (tolower(s[l]) != tolower(s[r])) {
                    return false;
                }
                l++;
                r--;
            }
        }
        
        return true;
    }
};
