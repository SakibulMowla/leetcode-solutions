class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        vector<int> cnt(26, 0);
        for (char task : tasks) {
            cnt[task - 'A']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                pq.push(cnt[i]);
            }
        }

        int ans = 0;
        while (!pq.empty()) {
            int lim = min(n + 1, (int)pq.size());
            vector<int> tmp;
            for (int i = 0; i < lim; i++) {
                int top = pq.top();
                pq.pop();
                if (top - 1) {
                    tmp.push_back(top - 1);
                }
            }
            ans += lim;
            for (int num : tmp) {
                pq.push(num);
            }
            if (pq.size()) {
                ans += n + 1 - lim;
            }
        }

        return ans;
    }
};
