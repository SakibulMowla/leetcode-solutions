----------------------------------------------
// Sort and Iterate - O(nlgn)
----------------------------------------------

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int ans = 1;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            } else if (nums[i] == nums[i-1] + 1) {
                cnt++;
            } else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};

----------------------------------------------
// Union Find - O(n)
----------------------------------------------

class Solution {
public:
    int findParent(unordered_map<int, int>& par, int r) {
        return r == par[r] ? r : findParent(par, par[r]);
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> par;
        unordered_map<int, int> groupSize;
        int ans = 0;
        for (int num: nums) {
            if (par.find(num) == par.end()) {
                par[num] = num;
                groupSize[num] = 1;
            }
            int numParent = findParent(par, num);
            for (int adj = num - 1; adj <= num + 1; adj += 2) {
                if (par.find(adj) != par.end()) {
                    int adjParent = findParent(par, adj);
                    if (numParent != adjParent) {
                        par[adjParent] = par[numParent];
                        groupSize[numParent] += groupSize[adjParent];   
                    }
                }   
            }
            ans = max(ans, groupSize[numParent]);
        }
        return ans;
    }
};
