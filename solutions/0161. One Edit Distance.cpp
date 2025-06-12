class Solution {
private:
    bool isOneMismatch(string& s, string& t) {
        int len = s.size(), mismatch = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] != t[i]) {
                mismatch++;
            }
            if (mismatch > 1) {
                break;
            }
        }

        return mismatch == 1;
    }

    bool isOneDeletion(string& s, string& t) {
        int sLen = s.size(), tLen = t.size();
        
        int i = 0, j = 0, skip = 0;
        while (i < sLen && j < tLen) {
            if (s[i] != t[j]) {
                skip++;
                i++;
            } else {
                i++;
                j++;
            }

            if (skip > 1) {
                break;
            }
        }

        if (i < sLen) {
            skip += sLen - i;
        }

        return skip == 1;
    }

public:
    bool isOneEditDistance(string s, string t) {
        int sLen = s.size(), tLen = t.size();

        if (sLen == tLen) {
            return isOneMismatch(s, t);
        }

        if (abs(sLen - tLen) > 1) {
            return false;
        }

        if (sLen < tLen) {
            swap(s, t);
        }

        return isOneDeletion(s, t);
    }
};

// ------------------------------------------------------------------------------------------

// One pass

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sLen = s.size(), tLen = t.size();

        if (sLen < tLen) {
            return isOneEditDistance(t, s);
        }

        if (sLen - tLen > 1) {
            return false;
        }

        for (int i = 0; i < tLen; i++) {
            if (s[i] != t[i]) {
                if (sLen == tLen) {
                    return s.substr(i + 1) == t.substr(i + 1);
                } else {
                    return s.substr(i + 1) == t.substr(i);
                }
            }
        }

        return sLen == 1 + tLen;
    }
};
