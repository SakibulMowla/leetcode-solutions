class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        vector<set<int>> pillars;
        map<int, int> hash, rHash;

        int cnt = 0;
        for (auto& point: points) {
            int x = point[0];
            int y = point[1];
            if (hash.find(x) == hash.end()) {
                hash[x] = cnt;
                rHash[cnt] = x;
                pillars.push_back(set<int>());
                cnt++;
            }
            pillars[hash[x]].insert(y);
        }
    
        cnt = 0;
        map<pair<int, int>, int> seen;
        int ans = numeric_limits<int>::max();

        for (auto key: hash) {
            auto& pillar = pillars[key.second];
            for (auto it = pillar.begin(); it != pillar.end(); it++) {
                for (auto itj = next(it); itj != pillar.end(); itj++) {
                    int y1 = *it;
                    int y2 = *itj;
                    if (seen.find({y1, y2}) != seen.end()) {
                        ans = min(ans, (y2 - y1) * abs(seen[{y1, y2}] - key.first));
                    }
                    seen[{y1, y2}] = key.first;
                }
            }
        }
      
        return ans == numeric_limits<int>::max() ? 0 : ans;
    }
};
