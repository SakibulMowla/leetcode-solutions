class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> magazineCharCount(26, 0);
        for (char ch: magazine) {
            magazineCharCount[ch - 'a']++;
        }
        for (char ch: ransomNote) {
            magazineCharCount[ch - 'a']--;
            if (magazineCharCount[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
