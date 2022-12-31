class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charToCount;
        for (char ch: s) {
            charToCount[ch]++;
        }

        bool oddPresent = false;
        int length = 0;
        for (auto it: charToCount) {
            int count = it.second;
            if (count % 2 == 1) {
                oddPresent = true;
                count--;
            }
            length += count;
        }
 
        return length + (int)oddPresent;
    }
};
