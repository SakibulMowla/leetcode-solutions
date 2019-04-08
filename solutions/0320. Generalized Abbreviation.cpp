class Solution {
public:
    
    void dfs(vector<string>& ans,
             string& word,
             string& cur,
             int n,
             int pos,
             bool skip) {
        if (pos == n) {
            ans.push_back(cur);
        } else if (skip) {
            cur += word[pos];
            dfs(ans, word, cur, n, pos + 1, false);
            cur.erase(cur.size() - 1);
        } else {
            for (int i = n; i >= pos; i--) {
                int sz = 1;
                if (i == pos) {
                    cur += word[i];
                } else {
                    cur += to_string(i - pos);
                    sz = to_string(i - pos).size();
                }
                dfs(ans, word, cur, n, max(i, pos + 1), pos != i);
                cur.erase(cur.size() - sz);
            }
        }
        return;
    }
    
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        string cur;
        int n = word.size();
        dfs(ans, word, cur, n, 0, false);
        return ans;
    }
};




class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int n = word.size();
        int lim = (1 << n);
        
        vector<string> ans;
        int cnt;
        for (int mask = 0; mask < lim; mask++) {
            cnt = 0;
            string cur;
            for (int i = 0; i < n; i++) {
                int bit = (mask >> i) & 1;
                if (bit) {
                    cnt++;
                } else {
                    if (cnt) {
                        cur += to_string(cnt);
                        cnt = 0;
                    }
                    cur += word[i];
                }
            }
            if (cnt) {
                cur += to_string(cnt);
            }
            ans.push_back(cur);
        }

        return ans;
    }
};

