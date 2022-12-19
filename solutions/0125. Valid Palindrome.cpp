class Solution {
public:
    bool isPalindrome(string s) {
        int length = s.size();
        int left = 0, right = length - 1;

        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
            } else if (!isalnum(s[right])) {
                right--;
            } else if (toupper(s[left]) == toupper(s[right])) {
                left++;
                right--;
            } else {
                return false;
            }
        }

        return true;
    }
};
