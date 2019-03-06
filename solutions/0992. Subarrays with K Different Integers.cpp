class Solution {
public:
    void add(unordered_map<int, int>& hash, int val) {
        if (hash.find(val) == hash.end()) {
            hash[val] = 0;
        }
        hash[val]++;
        return;
    }

    void remove(unordered_map<int, int>& hash, int val) {
        hash[val]--;
        if (hash[val] == 0) {
            hash.erase(val);
        }
        return;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        int ans = 0;
        unordered_map<int, int> hashL, hashR;

        for (int l1 = 0, l2 = 0, r = 0; r < n; r++) {
            add(hashL, A[r]);
            add(hashR, A[r]);
            
            while (hashR.size() >= K) {
                remove(hashR, A[l1]);
                l1++;
            }
            
            while (hashL.size() > K) {
                remove(hashL, A[l2]);
                l2++;
            }
            
            ans += l1 - l2;
        }
        
        return ans;
    }
};
