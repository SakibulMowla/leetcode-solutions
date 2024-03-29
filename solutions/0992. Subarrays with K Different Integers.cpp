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

// -----------------------------------------------------

class Solution {
private:
    int subarraysWithUptoKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int ans = 0;
        for (int l = 0, r = 0, uniques = 0; r < nums.size(); r++) {
            if (count.find(nums[r]) == count.end()) {
                count[nums[r]] = 0;
                uniques++;
            }
            count[nums[r]]++;
            while (uniques > k) {
                count[nums[l]]--;
                if (count[nums[l]] == 0) {
                    count.erase(nums[l]);
                    uniques--;
                }
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithUptoKDistinct(nums, k) - subarraysWithUptoKDistinct(nums, k - 1);
    }
};
