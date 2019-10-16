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
