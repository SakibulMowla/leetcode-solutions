class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        for (auto pre: prerequisites) {
            inDegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            
            for (auto v: adj[front]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        if (ans.size() != numCourses) {
            ans.clear();
        }
        
        return ans;
    }
};
