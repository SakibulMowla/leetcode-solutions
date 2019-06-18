class Solution {
public:
    string insertRange(long long lft, long long rht) {
        if (lft == rht) {
            return to_string(lft);
        } else {
            return to_string(lft) + "->" + to_string(rht);
        }
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        long long prev = lower;
        vector<string> ans;

        for (int i = 0; i < len; i++) {
            if (nums[i] > prev) {
                ans.push_back(insertRange(prev, nums[i] - 1LL));
            }
            prev = nums[i] + 1LL;
        }
        if (prev <= upper) {
            ans.push_back(insertRange(prev, upper));
        }
        
        return ans;
    }
};
