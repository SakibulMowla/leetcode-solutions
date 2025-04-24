class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> uniques;
        for (int num: nums) {
            uniques[num]++;
        }
        int uniqueCount = uniques.size();
        uniques.clear();

        int ans = 0;
        for (int left = 0, right = 0; right < nums.size(); right++) {
            uniques[nums[right]]++;
            while (uniques.size() == uniqueCount) {
                ans += nums.size() - right;
                
                uniques[nums[left]]--;
                if (uniques[nums[left]] == 0) {
                    uniques.erase(nums[left]);
                }
                left++;
            }
        }

        return ans;
    }
};
