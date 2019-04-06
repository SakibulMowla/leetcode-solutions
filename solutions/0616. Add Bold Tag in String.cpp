class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.size();
        vector<int> cnt(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            for (auto& word: dict) if (i + word.size() <= n) {
                bool flag = true;
                for (int j = 0; j < word.size(); j++) {
                    if (s[i + j] != word[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cnt[i]++;
                    cnt[i + word.size()]--;
                }
            }
        }
        
        string ans;
        for (int i = 0; i <= n; i++) {
            if (i) {
                cnt[i] += cnt[i - 1];
            }
            int pre = i ? cnt[i - 1] : 0;
            if (pre == 0 && cnt[i] > 0) {
                ans += "<b>";
            }
            if (pre > 0 && cnt[i] == 0) {
                ans += "</b>";
            }
            if (i < n) {
                ans += s[i];
            }
        }
        
        return ans;
    }
};
