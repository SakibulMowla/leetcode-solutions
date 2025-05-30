class Solution {
private:
    long long base = 26;
    long long mod = 1E9 + 7;

    bool compare(string& a, string& b, int index) {
        int len = a.size();

        for (int i = 0; i < len; i++) {
            if (i == index) {
                continue;
            }
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }

public:
    bool differByOne(vector<string>& dict) {
        int n = dict.size();
        if (n <= 1) {
            return false;
        }

        int m = dict[0].size();
        vector<int> hashes(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                hashes[i] = (base * hashes[i] + (dict[i][j] - 'a')) % mod;
            }
        }

        long long mult = 1;
        for (int j = m - 1; j >= 0; j--) {
            unordered_map<int, vector<int>> hashToIndex;

            for (int i = 0; i < n; i++) {
                int tmpHash = ((hashes[i] - mult * (dict[i][j] - 'a')) % mod + mod) % mod;

                if (hashToIndex.find(tmpHash) != hashToIndex.end()) {
                    for (int it: hashToIndex[tmpHash]) {
                        if (compare(dict[i], dict[it], j)) {
                            return true;
                        }
                    }
                }

                hashToIndex[tmpHash].push_back(i);
            }

            mult = (mult * base) % mod;
        }

        return false;
    }
};
