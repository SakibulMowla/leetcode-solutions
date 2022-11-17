class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (numToIndex.find(target - nums[i]) != numToIndex.end()) {
                return {numToIndex[target - nums[i]], i};
            }
            numToIndex[nums[i]] = i;
        }
        return {-1, -1}; 
    }
};
