// Hashing Approach
// Time - O(n)
// Memory - O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counter;
        for (int num: nums) {
            counter[num]++;
            if (counter[num] > n / 2) {
                return num;
            }
        }
        return -1;
    }
};

// Sorting Approach
// Time - O(nlogn)
// Memory - O(1)

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

// Boyer–Moore majority vote algorithm
// Time - O(n)
// Memory - O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int sum = 0;

        for (int num: nums) {
            if (sum == 0) {
                candidate = num;
            }
            sum += candidate == num ? 1 : -1;
        }

        return candidate;
    }
};
