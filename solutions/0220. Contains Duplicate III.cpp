class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        set<int> numsSet;
        for (int i = 0; i < n; i++) {
            auto it = numsSet.upper_bound(nums[i]);

            if (it != numsSet.end()) {
                if (*it - nums[i] <= valueDiff) {
                    return true;
                }
            }

            if (it != numsSet.begin()) {
                if (nums[i] - *prev(it) <= valueDiff) {
                    return true;
                }
            }

            // insert element
            numsSet.insert(nums[i]);

            // remove element
            if (i >= indexDiff) {
                numsSet.erase(numsSet.find(nums[i - indexDiff]));
            }
        }

        return false;
    }
};
