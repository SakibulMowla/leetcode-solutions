class Solution {
public:
    
    void nextChar(string& s, int& pos) {
        int cnt = 0;
        for (pos--; pos >= 0; pos--) {
            if (s[pos] == '#') {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt == -1) {
                break;
            }
        }
        return;
    }

    bool backspaceCompare(string S, string T) {
        int sPos = S.size(), tPos = T.size();
        bool flag = true;
        while (true) {
            nextChar(S, sPos);
            nextChar(T, tPos);
            if (sPos == -1 && tPos == -1) {
                break;
            } else if (sPos == -1 || tPos == -1 || S[sPos] != T[tPos]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};
