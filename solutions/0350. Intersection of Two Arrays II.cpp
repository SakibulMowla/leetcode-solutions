class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt;
        for (int num: nums1) {
            if (cnt.find(num) == cnt.end()) {
                cnt[num] = 0;
            }
            cnt[num]++;
        }
        
        vector<int> ans;
        for (int num: nums2) {
            if (cnt.find(num) != cnt.end() && cnt[num]) {
                cnt[num]--;
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};
