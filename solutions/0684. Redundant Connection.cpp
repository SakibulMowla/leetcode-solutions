class Solution {
public:
    
    int findPar(int r, vector<int>& par) {
        return r == par[r] ? r : findPar(par[r], par);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for (auto& edge: edges) {
            n = max(n, max(edge[0], edge[1]));
        }
        
        vector<int> par(n + 1);
        for (int i = 1; i <= n; i++) {
            par[i] = i;
        }
        
        vector<int> ans;

        for (auto& edge: edges) {
            int x = findPar(edge[0], par);
            int y = findPar(edge[1], par);
            if (x == y) {
                ans = edge;
                break;
            } else {
                par[y] = x;
            }
        }
        
        return ans;
    }
};
