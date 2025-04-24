// Math
// Time - O(n)
// Memory - O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int num: nums) {
            sum += num;
        }
        
        return (n * (n + 1) / 2) - sum;
    }
};

// Bit Manipulation
// Time - O(n)
// Memory - O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int allXor = 0, containerXor = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            allXor ^= i;
            containerXor ^= nums[i];
        }
        containerXor ^= n;

        return allXor ^ containerXor;
    }
};
