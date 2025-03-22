class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> freq;
        for (char ch: t) {
            freq[ch]++;
        }

        int required = freq.size();
        int minLen = numeric_limits<int>::max(), pos = 0;

        for (int start = 0, end = 0; end < s.size(); end++) {
            char ch = s[end];
            if (freq.find(ch) != freq.end()) {
                freq[ch]--;
                if (freq[ch] == 0) {
                    required--;
                }
            }

            while (required == 0) {
                if (freq.find(s[start]) != freq.end()) {
                    freq[s[start]]++;
                    if (freq[s[start]] == 1) {
                        required++;
                    }
                }
                if (minLen > end - start + 1) {
                    minLen = end - start + 1;
                    pos = start;
                }
                start++;
            }
        }

        return minLen == numeric_limits<int>::max() ? "" : s.substr(pos, minLen);
    }
};
