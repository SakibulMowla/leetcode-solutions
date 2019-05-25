class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> hash;
        int n = tree.size();
        int ans = 0;

        for (int l = 0, r = 0; r < n; r++) {
            hash[tree[r]]++;
            while (hash.size() == 3) {
                hash[tree[l]]--;
                if (hash[tree[l]] == 0) {
                    hash.erase(tree[l]);
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};
