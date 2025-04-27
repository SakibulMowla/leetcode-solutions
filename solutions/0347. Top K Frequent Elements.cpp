// Time - O(n log k)
// Memory - O(n + k)

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

// ---------------------------------------------

// Time - O(n log k)
// Memory - O(n + k)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num: nums) {
            count[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minQueue;
        for (auto it: count) {
            minQueue.push({it.second, it.first});
            if (minQueue.size() > k) {
                minQueue.pop();
            }
        }

        vector<int> ans;
        while (!minQueue.empty()) {
            ans.push_back(minQueue.top().second);
            minQueue.pop();
        }

        return ans;
    }
};

// ---------------------------------------------

// Time - O(n)
// Memory - O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num: nums) {
            count[num]++;
        }

        vector<vector<int>> freq(nums.size() + 1);
        for (auto it: count) {
            freq[it.second].push_back(it.first);
        }

        vector<int> ans;
        int ansLen = 0;
        for (int i = nums.size(); i >= 1; i--) {
            for (int element: freq[i]) {
                ans.push_back(element);
                ansLen++;
            }
            if (ansLen == k) {
                break;
            }
        }

        return ans;
    }
};
