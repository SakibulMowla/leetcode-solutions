// Hashing Approach

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;

        for (auto &num: nums) {
            hash[num]++;
        }

        int ans;
        for (auto it: hash) {
            if (it.second > n / 2) {
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};

// Sorting Approach

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans;
        for (int i = 0, cnt = 0; i < n; i++) {
            if (i && nums[i] == nums[i - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            if (cnt > n / 2) {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};
