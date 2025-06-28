// DP

class Solution {
private:
    int n;
    unordered_map<int, int> posToIndex;
    vector<vector<int>> dp;

    bool solve(int cur, int prev, vector<int>& stones) {
        if (cur == n - 1)
            return true;
        
        int ret = dp[cur][prev];
        if (ret != -1)
            return ret == 1;
        
        ret = 0;
        int lastJump = stones[cur] - stones[prev];
        for (int nextJump = lastJump - 1; nextJump <= lastJump + 1; nextJump++) {
            int nextPos = stones[cur] + nextJump;
            if (posToIndex.contains(nextPos) && posToIndex[nextPos] > cur) {
                ret = max(ret, (int)solve(posToIndex[nextPos], cur, stones));
            }
        }

        return dp[cur][prev] = ret;
    }

public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1)
            return false;

        n = stones.size();
        for (int i = 0; i < n; i++) {
            posToIndex[stones[i]] = i;
        }
        dp = vector<vector<int>>(n, vector<int> (n, -1));

        return solve(1, 0, stones);
    }
};

// BFS

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1)
            return false;

        unordered_map<int, int> posToIndex;
        int n = stones.size();
        for (int i = 0; i < n; i++) 
            posToIndex[stones[i]] = i;

        queue<pair<int, int>> q;
        q.push({1, 1}); // index, last jump
        vector<vector<int>> dist(n, vector<int> (n, false));

        while (!q.empty()) {
            auto [cur, lastJump] = q.front();
            q.pop();

            if (cur == n - 1)
                return true;

            for (int nextJump = lastJump - 1; nextJump <= lastJump + 1; nextJump++) {
                int nextPos = stones[cur] + nextJump;
                if (posToIndex.contains(nextPos) &&
                    posToIndex[nextPos] > cur &&
                    !dist[posToIndex[nextPos]][cur]) {
                    q.push({posToIndex[nextPos], nextJump});
                    dist[posToIndex[nextPos]][cur] = true;
                }
            }
        }

        return false;
    }
};
