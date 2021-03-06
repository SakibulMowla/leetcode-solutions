class Solution {
public:
    bool check(string str, string t) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != t[i % t.size()]) {
                return false;
            }
        }
        return true;
    }
    
    string gcdOfStrings(string str1, string str2) {
        int size1 = str1.size();
        int size2 = str2.size();
        
        int mn = min(size1, size2);
        string ans;

        for (int i = mn; i >= 1; i--) {
            if (size1 % i == 0 && size2 % i == 0) {
                string t = str1.substr(0, i);
                if (check(str1, t) && check(str2, t)) {
                    ans = t;
                    break;
                }
            }
        }
        
        return ans;
    }
};
