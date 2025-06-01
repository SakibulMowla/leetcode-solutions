class Solution {
private:
    map<pair<char, char>, vector<char>> adj;
    unordered_set<string> seen; 

    void buildGraph(vector<string>& allowed) {
        for (string& edge: allowed) {
            adj[{edge[0], edge[1]}].push_back(edge[2]);
        }
        return;
    }

    bool dfs(int index, string& cur, string& prev) {
        if (prev.size() == 1) {
            return true;
        }

        if (index == prev.size() - 1) {
            if (seen.find(cur) != seen.end()) {
                return false;
            }
            seen.insert(cur);

            string newCur = "";
            return dfs(0, newCur, cur);
        }

        bool found = false;
        for (auto it: adj[{prev[index], prev[index + 1]}]) {
            cur.push_back(it);
            found = dfs(index + 1, cur, prev);
            cur.pop_back();

            if (found) {
                break;
            }
        }

        return found;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        buildGraph(allowed);    

        string cur = "";
        return dfs(0, cur, bottom);
    }
};
