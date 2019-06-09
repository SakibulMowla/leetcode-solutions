class Solution {
public:
    struct data {
        char ch;
        int cnt;
        data(char ch, int cnt): ch(ch), cnt(cnt) {}
    };
    
    vector<data> decompose(string S) {
        vector<data> reform;
        int n = S.size();

        for (int i = 0; i < n; i++) {
            int j = i;
            while (j + 1 < n && S[j + 1] == S[j]) j++;
            reform.push_back(data(S[i], j - i + 1));
            i = j;
        }

        return reform;
    }

    bool stressable(vector<data>& base, vector<data>& disguise) {
        if (base.size() != disguise.size()) {
            return false;
        }
        int n = base.size();
        for (int i = 0; i < n; i++) {
            bool cntCalc = (base[i].cnt == disguise[i].cnt) ||
                           (base[i].cnt > disguise[i].cnt &&
                           base[i].cnt >= 3);
            if ((base[i].ch != disguise[i].ch) ||
               !cntCalc) {
                return false;
            }
        }
        return true;
    }
    
    int expressiveWords(string S, vector<string>& words) {
        vector<data> base = decompose(S);
        int cnt = 0;

        for (auto& word: words) {
            vector<data> disguise = decompose(word);
            if (stressable(base, disguise)) {
                cnt++;
            }
        }
        
        return cnt;
    }
};
