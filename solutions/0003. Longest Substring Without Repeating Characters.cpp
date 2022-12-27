class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int startIndex = 0;
        int ans = 0;
        unordered_map<char, int> lastIndex;

        for (int i = 0; i < s.size(); i++) {
            if (lastIndex.find(s[i]) != lastIndex.end()) {
                startIndex = max(startIndex, lastIndex[s[i]] + 1);
            }
            lastIndex[s[i]] = i;
            ans = max(ans, i - startIndex + 1);
        }
       
        return ans;
    }
};
