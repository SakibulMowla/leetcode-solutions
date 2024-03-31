
/*
Time - O(n)
Space - O(n)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto num: nums) {
            if (hash.find(num) != hash.end()) {
                return true;
            }
            hash.insert(num);
        }
        return false;
    }
};
// -------------------------------------------
/*
Time - O(nlogn)
Space - O(1)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }   
        return false;
    }
};
