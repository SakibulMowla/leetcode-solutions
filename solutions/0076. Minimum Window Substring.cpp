class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tHash;
        for (char ch: t) {
            if (tHash.find(ch) == tHash.end()) {
                tHash[ch] = 0;
            }
            tHash[ch]++;
        }
        
        int uniques = tHash.size();
        int got = 0;
        int ans = s.size() + 1;
        int start = -1;
        unordered_map<char, int> sHash;

        for (int l = 0, r = 0; r < s.size(); r++) {
            char ch = s[r];
            if (tHash.find(ch) != tHash.end()) {
                sHash[ch]++;
                if (sHash[ch] == tHash[ch]) {
                    got++;
                }
            }
            while (got == uniques) {
                char ch = s[l];
                if (sHash.find(ch) != sHash.end()) {
                    if (sHash[ch] == tHash[ch]) {
                        break;
                    }
                    sHash[ch]--;
                }
                l++;
            }
            if (got == uniques) {
                if (r - l + 1 < ans) {
                    ans = r - l + 1;
                    start = l;
                }
            }
        }
        
        return start == -1 ? "" : s.substr(start, ans);
    }
};
