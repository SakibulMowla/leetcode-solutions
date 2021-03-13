class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> inDegree;
        for (string word: words) {
            for (char ch: word) {
                inDegree[ch] = 0;
            }
        }
        
        vector<unordered_set<char>> adj(26, unordered_set<char>()); // adjacency list
        int n = words.size();
        
        for (int i = 1; i < n; i++) {
            int len = min(words[i].size(), words[i - 1].size());
            bool flag = false;
            for (int j = 0; j < len; j++) {
                char u = words[i - 1][j];
                char v = words[i][j];
                if (u != v) {
                    if (adj[u - 'a'].find(v) == adj[u - 'a'].end()) {
                        adj[u - 'a'].insert(v);
                        inDegree[v]++;
                    }
                    flag = true;
                    break;
                }
            }
            if (!flag && words[i - 1].size() > words[i].size()) {
                return "";
            }
        }
        
        queue<char> q;
        
        for (auto it: inDegree) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }
        
        
        string ans;

        while (!q.empty()) {
            char front = q.front();
            q.pop();
            
            ans += front;
            for (auto it: adj[front - 'a']) {
                inDegree[it]--;
                if (inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return ans.size() == inDegree.size() ? ans : "";
    }
};
