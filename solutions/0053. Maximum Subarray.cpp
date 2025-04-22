/*
Time - O(n)
Space - O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
};

// ---------------------------------------
/*
Time - O(nlogn)
Space - O(logn)
*/

class Solution {
private:
    int maxSubArrayRange(vector<int>& nums, int left, int right) {
        if (left > right) {
            return numeric_limits<int>::min();
        }

        int mid = (left + right) / 2;
        int maxLeftSum = 0, maxRightSum = 0;

        for (int i = mid + 1, sum = 0; i <= right; i++) {
            sum += nums[i];
            maxRightSum = max(maxRightSum, sum);
        }

        for (int i = mid - 1, sum = 0; i >= left; i--) {
            sum += nums[i];
            maxLeftSum = max(maxLeftSum, sum);
        }

        int bestCombined = nums[mid] + maxLeftSum + maxRightSum;

        int leftAns = maxSubArrayRange(nums, left, mid - 1);
        int rightAns = maxSubArrayRange(nums, mid + 1, right);

        return max(bestCombined, max(leftAns, rightAns));
    }

public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayRange(nums, 0, nums.size() - 1);
    }
};

// 
/*
Optimized Divide and Conquer
Time - O(nlogn)
Space - O(n)
*/

class Solution {
private:
    int divideAndConquer(int left, int right, vector<int>& nums, vector<int>& prefix, vector<int>& suffix) {
        if (left == right) {
            return nums[left];
        }
        
        int mid = left + (right - left) / 2;
        
        int best = max(
                       prefix[mid] + suffix[mid + 1],
                       max(
                           divideAndConquer(left, mid, nums, prefix, suffix),
                           divideAndConquer(mid + 1, right, nums, prefix, suffix)
                       )
                   );
        
        return best;
    }

public:
    int maxSubArray(vector<int>& nums) {
        vector<int> prefix(nums), suffix(nums);
        
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            prefix[i] += max(0, prefix[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] += max(0, suffix[i + 1]);
        }

        return divideAndConquer(0, n - 1, nums, prefix, suffix);
    }
};
