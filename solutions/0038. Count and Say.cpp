class Solution {
private:    
    string nextInSeq(const string& base) {
        string ans;
        for (int j = 0; j < base.size(); j++) {
            int k = j;
            while (k + 1 < base.size() && base[k + 1] == base[j]) {
                k++;
            }
            ans += to_string(k - j + 1) + base[j];
            j = k;
        }
        return ans;
    }

public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; i++) {
            ans = nextInSeq(ans);
        }
        return ans;
    }
};
