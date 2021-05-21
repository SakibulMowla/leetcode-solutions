class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash;
        for (int num: nums1) {
            hash.insert(num);
        }
        
        unordered_set<int> ansSet;
        for (int num: nums2) {
            if (hash.find(num) != hash.end()) {
                ansSet.insert(num);
            }
        }
        
        vector<int> ans;
        for (auto it: ansSet) {
            ans.push_back(it);
        }
        
        return ans;
    }
};
