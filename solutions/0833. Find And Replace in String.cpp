class Solution {
public:
    bool match(string& S, string& T, int buffer) {
        int sLen = S.size(), tLen = T.size();
        if (buffer + tLen > sLen) {
            return false;
        }
        for (int i = 0; i < tLen; i++) {
            if (T[i] != S[i + buffer]) {
                return false;
            }
        }
        return true;
    }

    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        vector<int> mark(S.size(), -2);

        for (int i = 0; i < n; i++) {
            if (match(S, sources[i], indexes[i])) {
                int k = sources[i].size();
                mark[indexes[i]] = i;
                for (int j = 1; j < k; j++) {
                    mark[indexes[i] + j] = -1;
                }
            }
        }

        string ans;
        for (int i = 0; i < S.size(); i++) {
            if (mark[i] == -2) {
                ans += S[i];
            } else if (mark[i] >= 0) {
                ans += targets[mark[i]];
            }
        }
        
        return ans;
    }
};
