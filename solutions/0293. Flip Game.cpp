class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        int n = s.size();
        vector<string> ans;
        for (int i = 1; i < n; i++) {
            string t = s;
            if (s[i] == s[i - 1] && s[i] == '+') {
                t[i] = '-';
                t[i - 1] = '-';
                ans.push_back(t);
            }
        }
        return ans;
    }
};

