class UnionFind {
    int n;
    vector<int> par, size;

public:
    
    UnionFind(int n) {
        this->n = n;
        par = vector<int> (n);
        size = vector<int> (n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int r) {
        if (r == par[r])
            return r;
        return par[r] = find(par[r]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return;

        par[u] = v;
        size[v] += size[u];
    }

    int findComponentSize() {
        int par = find(n - 1);
        return size[par];
    }
};

class Solution {
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int rows, cols;

    bool isWithinGrid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<vector<int>> gridCopy = grid;
        // set gridCopy as the grid before hits
        for (auto& hit: hits) {
            gridCopy[hit[0]][hit[1]] = 0;
        }

        rows = grid.size();
        cols = grid[0].size();

        UnionFind uf(rows * cols + 1);

        // add hits 1 by 1 to the gridCopy
        // and record the union/merge of nodes
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                if (gridCopy[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int adjI = i + dx[k];
                        int adjJ = j + dy[k];
                        if (isWithinGrid(adjI, adjJ) && gridCopy[adjI][adjJ] == 1) {
                            int u = i * cols + j;
                            int v = adjI * cols + adjJ;
                            uf.merge(u, v);
                        }
                    }
                }
            }

        // connect top row with the supernode (rows * cols)
        // all nodes are connected to supernode; used for calculating grid size
        for (int j = 0; j < cols; j++) {
            if (gridCopy[0][j] != 1)
                continue;

            int u = j;
            int v = rows * cols;
            uf.merge(u, v);
        }

        int componentSize = uf.findComponentSize();
        vector<int> ans(hits.size());

        // now add back the hits 1 by 1 from the end of the hits list
        // observe how the component size changes, that will contruct the ans list
        for (int p = hits.size() - 1; p >= 0; p--) {
            auto& hit = hits[p];
            int i = hit[0], j = hit[1];
            if (grid[i][j] != 1) {
                ans[p] = 0;
                continue;
            }

            gridCopy[i][j] = 1;

            for (int k = 0; k < 4; k++) {
                int adjI = i + dx[k];
                int adjJ = j + dy[k];
                if (isWithinGrid(adjI, adjJ) && gridCopy[adjI][adjJ] == 1) {
                    int u = i * cols + j;
                    int v = adjI * cols + adjJ;
                    uf.merge(u, v);
                }
            }

            if (i == 0) {
                int u = j;
                int v = rows * cols;
                uf.merge(u, v);
            }

            int newComponentSize = uf.findComponentSize();
            ans[p] = max(0, newComponentSize - componentSize - 1);

            componentSize = newComponentSize;
        }

        return ans;
    }
};
