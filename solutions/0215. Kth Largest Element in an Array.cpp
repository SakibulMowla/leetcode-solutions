// ------------------- multiset ------------------------ //
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset <int> ms;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            ms.insert(nums[i]);
        }
        for (int i = k; i < n; i++) {
            ms.insert(nums[i]);
            ms.erase(ms.begin());
        }
        return *ms.begin();
    }
};

// --------------------- Priority Queue -------------------- //
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k) {
                pq.push(nums[i]);
            } else {
                int tp = pq.top();
                if (nums[i] > tp) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }
};
