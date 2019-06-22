class Solution {
public:
    struct data {
        char ch;
        int cnt;
        data(char ch, int cnt): ch(ch), cnt(cnt) {}
        bool operator < (const data& x) const {
            return x.cnt > cnt;
        }
    };

    string reorganizeString(string S) {
        unordered_map<char, int> hash;
        for (auto ch: S) {
            if (hash.find(ch) == hash.end()) hash[ch] = 0;
            hash[ch]++;
        }
        
        priority_queue<data> pq;
        for (auto it: hash) {
            pq.push(data(it.first, it.second));
        }
        
        string ans;
        while (pq.size() >= 2) {
            data u = pq.top();
            pq.pop();
            data v = pq.top();
            pq.pop();
            ans += u.ch;
            ans += v.ch;
            --u.cnt;
            --v.cnt;
            if (u.cnt != 0) pq.push(u);
            if (v.cnt != 0 ) pq.push(v);
        }
        
        if (!pq.empty()) {
            data u = pq.top();
            if (u.cnt == 1) {
                ans += u.ch;
            } else {
                return "";
            }
        }
        
        return ans;
    }
};
