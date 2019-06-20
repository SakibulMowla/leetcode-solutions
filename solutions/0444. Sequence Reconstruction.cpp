class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<int> inDegree(n + 1, -1);
        vector<vector<int>> edges(n + 1, vector<int>());

        for (auto& seq: seqs) if (seq.size()) {
            if (seq[0] > n || seq[0] < 1) return false;
            if (inDegree[seq[0]] == -1) inDegree[seq[0]] = 0;
            for (int i = 1; i < seq.size(); i++) {
                if (seq[i] > n || seq[i] < 1) return false;
                if (inDegree[seq[i]] == -1) inDegree[seq[i]] = 0;
                inDegree[seq[i]]++;
                edges[seq[i - 1]].push_back(seq[i]);
            }
        }

        queue<int> Q;
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                Q.push(i);
            }
        }
        
        int ptr = 0;
        while(!Q.empty()) {
            if (Q.size() != 1 || ptr == n) {
                return false;
            }
            int u = Q.front();
            Q.pop();
            if (u != org[ptr++]) {
                return false;
            }
            for (auto v: edges[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    Q.push(v);
                }
            }
        }
        
        return ptr == n;
    }
};
