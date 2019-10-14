class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;

    int solve(int lft, int mask, VVI& dp, VI& A) {
        if (lft == 0) {
            return mask == 0;
        }

        int &ret = dp[lft][mask];
        if (ret != -1) return ret;
        
        ret = 0;
        for (auto a: A) {
            ret += solve(lft - 1, mask & a, dp, A);
        }
        
        return ret;
    }
    
    int countTriplets(vector<int>& A) {
        int n = A.size();
        int lim = (1 << 16);
        VVI dp(4, VI(lim, -1));
        return solve(3, lim - 1, dp, A);
    }
};

class Solution {
public:
    int countTriplets(vector<int>& A) {
        unordered_map<int, int> hash;
        for (auto& a: A) {
            for (auto& b: A) {
                hash[a & b]++;
            }
        }
        
        int ans = 0;
        for (auto& a: A) {
            for (auto& it: hash) {
                if ((a & it.first) == 0) {
                    ans += it.second;
                }
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int countTriplets(vector<int>& A) {
        vector<int> hash(1 << 16, 0);

        for (auto& a: A) {
            for (auto& b: A) {
                hash[a & b]++;
            }
        }
        
        int ans = 0;
        for (auto& a: A) {
            for (int i = 0; i < (1 << 16); i++) {
                if ((a & i) == 0) {
                    ans += hash[i];
                }
            }
        }
        
        return ans;
    }
};
