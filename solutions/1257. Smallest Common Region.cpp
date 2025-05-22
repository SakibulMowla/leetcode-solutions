class Solution {
private:
    void buildParMap(vector<vector<string>>& regions, unordered_map<string, string>& par) {
        for (auto& region: regions) {
            for (int i = 1; i < region.size(); i++) {
                par[region[i]] = region[0];
            }
        }
        return;
    }

    void traverse(string& region, unordered_map<string, string>& par, unordered_set<string>& visited) {
        visited.insert(region);

        if (par.find(region) == par.end()) {
            return;
        }

        traverse(par[region], par, visited);
    }

    string findSmallest(string& region, unordered_map<string, string>& par, unordered_set<string>& visited) {
        if (visited.find(region) != visited.end()) {
            return region;
        }

        return findSmallest(par[region], par, visited);
    }

public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> par;
        buildParMap(regions, par);

        unordered_set<string> visited;
        traverse(region1, par, visited);

        return findSmallest(region2, par, visited);
    }
};
