class Solution {
public:
    using pii = pair<int, int>;

    struct data {
        pii cur;
        int cost;
        data(pii cur, int cost): cur(cur), cost(cost) {}
    };
    
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    
    int bfs(vector<vector<int>>& forest, int rows, int cols, pii start, pii target) {
        if (start == target) {
            return 0;
        }
        vector<vector<bool>> seen(rows, vector<bool> (cols, false));
        seen[start.first][start.second] = true;
        queue<data> q;
        q.push(data(start, 0));
        
        while (!q.empty()) {
            data tp = q.front();
            q.pop();
            
            if (tp.cur == target) {
                return tp.cost;
            }
            
            for (int k = 0; k < 4; k++) {
                pii nxt = {tp.cur.first + dx[k], tp.cur.second + dy[k]};
                if (nxt.first >= 0 && nxt.first < rows && nxt.second >= 0 && nxt.second < cols &&
                    forest[nxt.first][nxt.second] != 0 && !seen[nxt.first][nxt.second]) {
                    seen[nxt.first][nxt.second] = true;
                    q.push(data(nxt, tp.cost + 1));
                }
            }
        }
        
        return -1;
    }
    
    static bool comp(data& a, data& b) {
        return a.cost < b.cost;
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        int rows = forest.size();
        int cols = forest[0].size();
        
        vector<data> trees;
        trees.push_back(data({0, 0}, -1));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (forest[i][j] > 1) {
                    trees.push_back(
                        data({i, j}, forest[i][j])
                    );
                }
            }
        }
        
        sort(trees.begin(), trees.end(), comp);
        
        int ans = 0;
        for (int i = 1; i < trees.size(); i++) {
            int val = bfs(forest, rows, cols, trees[i - 1].cur, trees[i].cur);
            if (val == -1) {
                ans = -1;
                break;
            }
            ans += val;
        }
        
        return ans;
    }
};
