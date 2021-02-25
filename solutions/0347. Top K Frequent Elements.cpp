class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            if (freq.find(num) == freq.end()) {
                freq[num] = 0;
            }
            freq[num]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it: freq) {
            if (pq.size() < k) {
                pq.push(it.second);
            } else {
                int top = pq.top();
                if (it.second > top) {
                    pq.pop();
                    pq.push(it.second);
                }
            }
        }
        int limit = pq.top();
        vector<int> ans;
        for (auto it: freq) {
            if (it.second >= limit) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
