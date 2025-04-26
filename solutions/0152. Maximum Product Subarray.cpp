class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prevMax = 1, prevMin = 1;
        int ans = numeric_limits<int>::min();
        
        for (int num: nums) {
            int curMax = num, curMin = num;

            if (num > 0) {
                curMax = max(curMax, num * prevMax);
                curMin = min(curMin, num * prevMin);
            } else {
                curMax = max(curMax, num * prevMin);
                curMin = min(curMin, num * prevMax);
            }

            prevMax = curMax;
            prevMin = curMin;

            ans = max(ans, curMax);
        }

        return ans;
    }
};
