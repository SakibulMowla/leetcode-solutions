/*
Time - O(n)
Space - O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = 0;
        for (int num: nums) {
            currentSum += num;
            currentSum = max(num, currentSum);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
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
