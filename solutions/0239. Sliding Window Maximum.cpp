// ==================================
// Time - O(N log K), Memory - O(N + K)
// ==================================

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> hash;
        int n = nums.size();
        for (int i = 0; i < k - 1; i++) {
            hash.insert(nums[i]);
        }
        
        vector<int> ans;
        for (int i = k - 1; i < n; i++) {
            hash.insert(nums[i]);
            ans.push_back(*prev(hash.end()));
            hash.erase(hash.lower_bound(nums[i - k + 1]));
        }
        
        return ans;
    }
};

// ==================================
// Time - O(N), Memory - O(N + K)
// ==================================
class Solution {
private:
    void addToDeque(deque<int>& dq, vector<int>& nums, int pos) {
        while (!dq.empty() && nums[dq.back()] <= nums[pos]) {
            dq.pop_back();
        }
        dq.push_back(pos);
        return;
    }
    
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;

        for (int i = 0; i < k - 1; i++) {
            addToDeque(dq, nums, i);
        }
        
        vector<int> ans;
        for (int i = k - 1; i < n; i++) {
            addToDeque(dq, nums, i);
            ans.push_back(nums[dq.front()]);
            if (dq.front() <= i - k + 1) {
                dq.pop_front();
            }
        }
        
        return ans;
    }
};
