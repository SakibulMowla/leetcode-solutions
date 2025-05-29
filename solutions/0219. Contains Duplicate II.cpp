// Time - O(n)
// Memory - O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (numToIndex.find(num) != numToIndex.end() && i - numToIndex[num] <= k) {
                return true;
            }
            numToIndex[num] = i;
        }
        
        return false;    
    }
};

// --------------------------------------------------------

// Time - O(n)
// Memory - O(min(n, k))

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> numsWindow;
        for (int i = 0; i < nums.size(); i++) {
            if (numsWindow.find(nums[i]) != numsWindow.end()) {
                return true;
            }
            numsWindow.insert(nums[i]);
            if (i >= k) {
                numsWindow.erase(numsWindow.find(nums[i - k]));
            }
        }

        return false;
    }
};
