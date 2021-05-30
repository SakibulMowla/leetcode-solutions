class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int revertedHalf = 0;
        while (x > revertedHalf) {
            revertedHalf = revertedHalf * 10 + (x % 10);
            x /= 10;
        }
        
        return x == revertedHalf || x == revertedHalf / 10;
    }
};
