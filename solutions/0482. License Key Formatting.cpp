class Solution {
public:
    string getHyphenLess(string S) {
        string ans;
        for (auto& ch: S) {
            if (ch != '-') {
                ans += toupper(ch);
            }
        }
        return ans;
    }

    string makeKGroups(string S, int K) {
        reverse(S.begin(), S.end());
        int n = S.size();
        string ans;
        for (int i = 0; i < n; i += K) {
            ans += (i ? "-" : "") + S.substr(i, K);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string licenseKeyFormatting(string S, int K) {
        return makeKGroups(getHyphenLess(S), K);
    }
};
