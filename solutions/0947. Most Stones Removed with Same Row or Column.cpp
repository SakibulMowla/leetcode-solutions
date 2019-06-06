class Solution {
public:
    int findPar(int r, vector<int>& par) {
        if (r != par[r]) {
            par[r] = findPar(par[r], par);
        }
        return par[r];
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> par(2 * 10000);

        for (int i = 0; i < 2 * 10000; i++) {
            par[i] = i;
        }

        for (int i = 0; i < n; i++) {
            int u = findPar(stones[i][0], par);
            int v = findPar(stones[i][1] + 10000, par);
            par[u] = v;
        }
        
        set<int> hash;
        for (int i = 0; i < n; i++) {
            int p = findPar(stones[i][0], par);
            hash.insert(p);
        }
        
        return n - hash.size();
    }
};
