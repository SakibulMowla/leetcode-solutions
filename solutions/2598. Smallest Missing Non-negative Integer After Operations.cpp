// Time - o(n log n)
// Memory - o(n)

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> count;
        for (int& num: nums) {
            int normalized = ((num % value) + value) % value;
            num = normalized + value * count[normalized];
            count[normalized]++;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i != nums[i]) {
                return i;
            }
        }

        return nums.size();
    }
};

// ---------------------------------------------------------------

// Time - o(n)
// Memory - o(n)

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();

        vector<int> count(value, 0);
        for (int num: nums) {
            count[((num % value) + value) % value]++;
        }

        for (int i = 0; i < n; i++) {
            if (count[i % value]) {
                count[i % value]--;
            } else {
                return i;
            }
        }

        return n;
    }
};
