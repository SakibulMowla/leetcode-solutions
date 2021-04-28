// Time - O(26 * n)

class Solution {
private:
    int uniqueCharCount(string& s) {
        unordered_set<char> hash;
        for (auto ch: s) {
            hash.insert(ch);
        }
        return hash.size();
    }

public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int totalUnique = uniqueCharCount(s);
        int ans = 0;
        
        for (int curUnique = 1; curUnique <= totalUnique; curUnique++) {
            int leftIndex = 0;
            int rightIndex = 0;
            int unique = 0;
            int kCntChars = 0;
            vector<int> freq(26, 0);
            while (rightIndex < n) {
                if (unique <= curUnique) {
                    int index = s[rightIndex] - 'a';
                    if (freq[index] == 0) {
                        unique++;
                    }
                    freq[index]++;
                    if (freq[index] == k) {
                        kCntChars++;
                    }
                    rightIndex++;
                } else {
                    int index = s[leftIndex] - 'a';
                    if (freq[index] == k) {
                        kCntChars--;
                    }
                    freq[index]--;
                    if (freq[index] == 0) {
                        unique--;
                    }
                    leftIndex++;
                }
                if (unique == curUnique && unique == kCntChars) {
                    ans = max(ans, rightIndex - leftIndex);
                }
            }
        }
        
        return ans;
    }
};
