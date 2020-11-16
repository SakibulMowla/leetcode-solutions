class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int ans = 0;
        int sum = 0;
        count[0] = 1;

        for (int num: nums) {
            sum += num;
            if (count.find(sum - k) != count.end()) {
                ans += count[sum - k];
            }
            if (count.find(sum) == count.end()) {
                count[sum] = 0;
            }
            count[sum]++;
        }
        
        return ans;
    }
};
